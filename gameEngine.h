#ifndef gameEngine_h
#define gameEngine_h

#include "actor.h"
#include "enemy.h"


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
void generateMob();
void drawBoarder();
void drawPlayerInfo();
void drawFightBoarder();

#endif gameEngine_h
