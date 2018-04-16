#include "fightEngine.h"



moveType playerMove;
moveType enemyMove;

uint16_t moveChoiseMade;
bool playerFirst;
bool turnComplete;
uint16_t eMoveChoise;
bool playerTurn;
spellNames playerAttack;
spellNames eAttack;

uint16_t eMoveStrength;




//take in 2 entities

void engage(actor& agressor, actor& target, moveType agesMove, moveType trgtMove, int attackmovepower){

      if(agesMove == attack){
        if(trgtMove == defend){
          target.takeDamage(agressor.damage(), (target.getStat(pgm_read_word(&target.type->statSeed.defense))));
          
        
        }else if( trgtMove == attack){
          target.takeDamage(agressor.damage(), 0);
          
        }
        else{ //magic/item use results in more damage taken
          target.takeDamage(agressor.damage(), 0); 
              
        }
      }
      else if (agesMove == defend)
      {          //target.takeDamage(agressor, -5); 
      }  
      else if (agesMove == item){
     // if (agressor.potion > 0){
      //agressor.usePotion();
      }//nothing
      else if (agesMove == skip){}
      else if (agesMove == special){
        
      }
      else if (agesMove == magic){
        target.takeSpecial(agressor);
        
      }
        
      
}

void Engagement(playerCharacter& plyr, actor& cpu){
if(state == 0){
//recieve player input
if(moveChoiseMade == 0){
  
  getPlayerMove(plyr);

// get cpu move
  getCPUMove();
  
  }
  else if (moveChoiseMade == 1 && eMoveChoise == 1){
  //determine which moves first
    if(plyr.getStat(pgm_read_word(&plyr.type->statSeed.speed)) > cpu.getStat(pgm_read_word(&cpu.type->statSeed.speed))) {
    playerFirst = true;
    }
    else{ playerFirst = false;}

    //execute commands

    if (playerFirst == true && turnComplete == false){
      engage(plyr, cpu, playerMove, enemyMove, pgm_read_word(&spellIndex[static_cast<uint8_t>(playerAttack)].strength));
      engage(cpu, plyr, enemyMove, playerMove, pgm_read_word(&spellIndex[static_cast<uint8_t>(playerAttack)].strength));

    //IMPLEMENT A PAUSE THAT READS ENEMY MOVE SELECTION
      //if (arduboy.everyXFrames(60)){
     // arduboy.print(enemyMove);}
      abuff = 1;
      turnComplete = true;
      moveChoiseMade = 0;
      state=1;

    }
    else if (playerFirst == false && turnComplete == false) {

      engage(cpu, plyr, enemyMove, playerMove, pgm_read_word(&spellIndex[static_cast<uint8_t>(playerAttack)].strength)); 
      engage(plyr, cpu, playerMove, enemyMove, pgm_read_word(&spellIndex[static_cast<uint8_t>(playerAttack)].strength));
      abuff = 1;
      turnComplete = true;
      moveChoiseMade = 0;
      state =1;
    }
//loop

  }
}

else if(state == 1){
  arduboy.clear();
  drawFightBoarder();
  drawPlayerInfo();
  arduboy.setCursor(70, 50);
  arduboy.print(F("continue"));
  arduboy.setCursor(6,4);
   if(enemyMove == defend){
         arduboy.println(F("The mob"));
         arduboy.setCursor(6,14);
         arduboy.println(F("Defended"));
          
        
        }else if( enemyMove == attack){
          arduboy.println(F("The mob"));
          arduboy.setCursor(6,14);
          arduboy.println(F("Attacked"));
          
        }
        else{
          arduboy.println(F("The mob"));
          arduboy.setCursor(6,14);
          arduboy.println(F("used ")); 
          arduboy.setCursor(6,24);
          arduboy.println(F("Magic")); 

              
        }
  if(arduboy.justPressed(A_BUTTON) and abuff ==0){
    abuff = 1;
    state = 0;}
  
}
}



void getPlayerMove(playerCharacter & plyr){
    if(menuNum ==0){
    turnComplete = false;
    if (menuCase > 3){ menuCase = 0;}
    if (menuCase < 0){menuCase = 3;} 

    switch (menuCase) {

      case 0:
      arduboy.print(F("Attack"));
      break;
      case 1:
      arduboy.print(F("Defend"));
      break;
      case 2:
      arduboy.print(F("Magic"));
      break;
      case 3:
      arduboy.print(F("Potion"));
      break;
   
    }


   if( arduboy.justPressed(A_BUTTON) == true and abuff ==0){
      abuff = 1;
      switch (menuCase) {
      
      case 0:
      playerMove = attack;
      menuNum = 1;
      break;
      case 1:
      playerMove = defend;
      moveChoiseMade = 1;
      break;
      case 2:
      playerMove = magic;
      menuNum =2;
      break;
      case 3:
      playerMove = item;
      moveChoiseMade = 1;  
      break;
    }
   }
    }
    else if(menuNum == 1){
     if (menuCase > pgm_read_word(plyr.type->attackListLength)){ menuCase = 0;}
    if (menuCase < 0){menuCase = pgm_read_word(plyr.type->attackListLength);} 
      arduboy.println(FlashString(pgm_read_word(&spellIndex[static_cast<uint8_t>(pgm_read_byte(&plyr.type->attackList[menuCase]))].name))); 
//    arduboy.println(FlashString(pgm_read_word(&attackIndex[static_cast<uint8_t>(plyr.type->attackList[menuCase])].name)));  

       if( arduboy.justPressed(A_BUTTON) == true and abuff ==0){
        abuff = 1;
        moveChoiseMade = 1;  
        menuNum = 0;
        playerAttack = pgm_read_word(plyr.type->attackList[menuCase]);
       }
       if( arduboy.justPressed(B_BUTTON) == true){
        menuNum = 0;  
       }
       
    }
    else if(menuNum == 2){
      if (menuCase > pgm_read_word(plyr.type->spellListLength)){ menuCase = 0;}
      if (menuCase < 0){menuCase = pgm_read_word(plyr.type->spellListLength);} 
      arduboy.println(FlashString(pgm_read_word(&spellIndex[static_cast<uint8_t>(pgm_read_byte(&plyr.type->spellList[menuCase]))].name)));  
       if( arduboy.justPressed(A_BUTTON) == true and abuff ==0){
        abuff = 1;
        moveChoiseMade = 1;  
        menuNum = 0;
       }
       if( arduboy.justPressed(B_BUTTON) == true){
        menuNum = 0;  
       }
    }
}

void getCPUMove(){
  uint16_t cpuAtkRand = rand() %3;

  switch (cpuAtkRand) {

      case 0:
      enemyMove = attack;
      eMoveChoise = 1;
      break;
      case 1:
      enemyMove = defend;
      eMoveChoise = 1;
      break;
      case 2:
      enemyMove = special;
      eMoveChoise = 1;
      break;
    }
}


void Attackpower(playerCharacter & plyr){   
    arduboy.println(FlashString(pgm_read_word(&spellIndex[static_cast<uint8_t>(plyr.type->attackList[menuCase])].name)));  
    if( arduboy.justPressed(A_BUTTON) == true and abuff ==0){
      abuff = 1;
      moveChoiseMade = 1;  
    }
}
  
   
