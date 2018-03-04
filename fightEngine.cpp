#include "gameEngine.h"
#include "Globals.h"
#include "actor.h"



int moveChoiseMade;
bool playerFirst;
bool turnComplete;
int eMoveChoise;


//take in 2 entities

void engage(actor& agressor, actor& target, moveType agesMove, moveType trgtMove){

      if(agesMove == attack){
        if(trgtMove == attack){
          target.takeDamage(agressor, 0);
        
        
        }else if( trgtMove == defend){
          target.takeDamage(agressor, (target.defense/5));
  
         }      
      }
      else if (agesMove = defend){}  
}

void Engagement(actor& plyr, actor& cpu){

//recieve player input
  if(moveChoiseMade == 0){
    turnComplete = false;
    if( arduboy.pressed(UP_BUTTON) == true and upbuff ==0){
      upbuff = 1;
      menuCase++;
    }
    if( arduboy.pressed(DOWN_BUTTON) == true and downbuff ==0){
       downbuff = 1;
       menuCase--;
    }
    if (menuCase > 1){ menuCase = 0;}
    if (menuCase < 0){menuCase = 1;} 

    switch (menuCase) {

      case 0:
      arduboy.print("attack");
      break;
      case 1:
      arduboy.print("defend");
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
    }
   }

   if( arduboy.notPressed(A_BUTTON) == true ) {
      abuff = 0;
      }
      if( arduboy.notPressed(UP_BUTTON) == true ) {
      upbuff = 0;
      }
      if( arduboy.notPressed(DOWN_BUTTON) == true ) {
      downbuff = 0;
     }

// get cpu move

  int cpuAtkRand = rand() %2;

  switch (cpuAtkRand) {

      case 0:
      enemyMove = attack;
      eMoveChoise = 1;
      break;
      case 1:
      enemyMove = defend;
      eMoveChoise = 1;
      break;
    }
  }
  else if (moveChoiseMade == 1 && eMoveChoise == 1){
  //determine which moves first
    if(plyr.speed > cpu.speed) {
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


