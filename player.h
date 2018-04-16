#ifndef player_h
#define player_h
#include "actor.h"
#include "weapons.h"
#include "images.h"
#include "attacks.h"




class playerCharacter: public actor{
  
public:
  playerCharacter(const actorType & type);
  uint16_t wallet;
  weaponId equiptedWpn;
  weaponId inv[5];
  uint16_t ex;
  uint8_t arenalvl;
  uint8_t potion;

  void printInv();
  void printStats();
  void equipt(uint16_t inventoryLocation);
  void checkLvlUp();
  void usePotion();
  void printMoves();
  
};


const char PROGMEM clssNmWarrior[] = "Warrior";
const char PROGMEM clssNmMage[] = "Mage";
const char PROGMEM clssNmTank[] = "Tank";

const  actorType actorList[] PROGMEM = {
  {clssNmWarrior, { 13, 13, 6, 6, 2 }, sword, warrior_bmp, {}, {Swipe}, 0, 1},
  {clssNmTank, { 20, 5, 10, 2, 3 }, sheild, tank_bmp, {}, {Bash}, 0 ,1},
  {clssNmMage, { 8, 5, 3, 2, 12 }, staff, mage_bmp, {Fire, Water, Cure}, {}, 3, 0},
};




#endif  player_h

