#include "gameEngine.h"
#include "Globals.h"
#include "actor.h"



uint16_t moveChoiseMade;
bool playerFirst;
bool turnComplete;
uint16_t eMoveChoise;


//take in 2 entities

void engage(actor& agressor, actor& target, moveType agesMove, moveType trgtMove){

      if(agesMove == attack){
        if(trgtMove == defend){
          target.takeDamage(agressor, (target.getStat(target.statSeed.defense)));
        
        
        }else if( trgtMove == attack){
          target.takeDamage(agressor, 0);
  
        }
        else{
          target.takeDamage(agressor, 2);      
        }
      }
      else if (agesMove == defend){}  
      else if (agesMove == special){
        target.takeSpecial(agressor);
      }
}

void Engagement(actor& plyr, actor& cpu){

//recieve player input
  if(moveChoiseMade == 0){
    turnComplete = false;
    if (menuCase > 2){ menuCase = 0;}
    if (menuCase < 0){menuCase = 2;} 

    switch (menuCase) {

      case 0:
      arduboy.print("attack");
      break;
      case 1:
      arduboy.print("defend");
      break;
      case 2:
      arduboy.print("Special");
      break;
   
    }


   if( arduboy.pressed(A_BUTTON) == true and abuff ==0){
      abuff = 1;
      switch (menuCase) {

      case 0:
      playerMove = attack;
      moveChoiseMade = 1;
      break;
      case 1:
      playerMove = defend;
      moveChoiseMade = 1;
      break;
      case 2:
      playerMove = special;
      moveChoiseMade = 1;
      break;
    }
   }


// get cpu move

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
  else if (moveChoiseMade == 1 && eMoveChoise == 1){
  //determine which moves first
    if(plyr.getStat(plyr.statSeed.speed) > cpu.getStat(cpu.statSeed.speed)) {
    playerFirst = true;
    }
    else{ playerFirst = false;}

    //execute commands

    if (playerFirst == true && turnComplete == false){
      engage(plyr, cpu, playerMove, enemyMove);
      engage(cpu, plyr, enemyMove, playerMove);

    //IMPLEMENT A PAUSE THAT READS ENEMY MOVE SELECTION
      if (arduboy.everyXFrames(60)){
      arduboy.print(enemyMove);}
      abuff = 1;
      turnComplete = true;
      moveChoiseMade = 0;

    }
    else if (playerFirst == false && turnComplete == false) {

      engage(cpu, plyr, enemyMove, playerMove); 
      engage(plyr, cpu, playerMove, enemyMove);
      abuff = 1;
      turnComplete = true;
      moveChoiseMade = 0;
    }
//loop

  }
}


