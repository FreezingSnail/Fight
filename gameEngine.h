#ifndef gameEngine_h
#define gameEngine_h

#include "actor.h"


void gameStart();
void Intro();
void MainMenu();
void fight();
void StatMenu();
void BattleScene(actor& opponent);
void VictoryScreen();
void Store();
void FailScreen();
void bossFight();

#endif gameEngine_h
