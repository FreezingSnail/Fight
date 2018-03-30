#ifndef Globals_h
#define Globals_h
#include <Arduboy2.h>

extern Arduboy2 arduboy;
extern uint8_t abuff;
extern uint8_t turnState;
extern uint8_t menuNum;
extern uint8_t state;

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



#endif // Globals_h

