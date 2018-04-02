#ifndef gameEngine_h
#define gameEngine_h

#include "actor.h"
#include "enemy.h"
#include "Globals.h"
#include "fightEngine.h"
#include "images.h"
#include "player.h"
#include "weapons.h"


void gameStart();
void Intro();
void MainMenu();
void fight();
void StatMenu();
void BattleScene(enemy& opponent);
void VictoryScreen();
void StoreRoom();
void FailScreen();
void bossFight();
void generateMob();
void drawBoarder();
void drawPlayerInfo();
void drawFightBoarder();
void setMob(const char * nm, weaponId wpn, baseStats seed, const byte * sprite, int lvl);
void Store(  weaponId storeInventory[], playerCharacter & player);
void browseInventory( weaponId storeInventory[], playerCharacter & player);
void placeInInv(playerCharacter & player, uint8_t itemSelected, const weaponId storeInventory[]);

#endif // gameEngine_h
