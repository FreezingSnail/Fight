#include "Globals.h"
#include "actor.h"
#include "gameEngine.h"


void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
  arduboy.initRandomSeed();
  int  menuCase = 0;
  gameStatus = intro;
  arduboy.clear();
   
}

//Main loop
void loop() {
  if(!arduboy.nextFrame()){
    return;
  }
  arduboy.pollButtons();

  if( arduboy.pressed(UP_BUTTON) == true and upbuff ==0){
      upbuff = 1;
      menuCase++;
    }
    if( arduboy.pressed(DOWN_BUTTON) == true and downbuff ==0){
      downbuff = 1;
       menuCase--;
    }

     if( arduboy.notPressed(UP_BUTTON) == true ) {
    upbuff = 0;
  }
  if( arduboy.notPressed(DOWN_BUTTON) == true ) {
    downbuff = 0;
  }
  if( arduboy.notPressed(A_BUTTON) == true ) {
    abuff = 0;
  }

  switch (gameStatus) {
     case GameStatus::intro:
     Intro();
     break;
     case GameStatus::charSelect:
     gameStart();
     break;
     case GameStatus::menu:
     MainMenu();
     break;
     case GameStatus::battle:
     fight();
     break;
     case GameStatus::statScreen:
     StatMenu();
     break;
     case GameStatus::store:
     Store();
     break;
     
  }  
  arduboy.display();
}
