#ifndef Globals_h
#define Globals_h
#include <Arduboy2.h>

extern Arduboy2 arduboy;
extern uint16_t abuff;
extern uint16_t turnState;
extern uint16_t menuNum;
extern uint16_t state;

enum GameStatus {
  intro,
  charSelect,
  menu,
  battle,
  gameOver,
  statScreen,
  store,
  bossBattle,
};

extern GameStatus gameStatus;
extern int menuCase;

enum moveType {
  attack,
  defend,
  special,
};

extern moveType playerMove;
extern moveType enemyMove;


#endif // Globals_h

