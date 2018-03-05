#ifndef Globals_h
#define Globals_h
#include <Arduboy2.h>

extern Arduboy2 arduboy;
extern int upbuff;
extern int downbuff;
extern int abuff;
extern int turnState;
extern int menuNum;

enum GameStatus {
  intro,
  charSelect,
  menu,
  battle,
  gameOver,
  statScreen,
  store,
};

extern GameStatus gameStatus;
extern int menuCase;

enum moveType {
  attack,
  defend,
};

extern moveType playerMove;
extern moveType enemyMove;


#endif Globals_h

