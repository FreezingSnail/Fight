#ifndef player_h
#define player_h
#include "actor.h"
#include "weapons.h"
#include "images.h"




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
  
};

const char PROGMEM clssNmWarrior[] = "Warrior";
const char PROGMEM clssNmMage[] = "Mage";
const char PROGMEM clssNmTank[] = "Tank";

const  actorType actorList[] PROGMEM = {
  {clssNmWarrior, { 13, 13, 6, 6, 2 }, sword, warrior_bmp},
  {clssNmTank, { 20, 5, 10, 2, 3 }, sheild, tank_bmp},
  {clssNmMage, { 8, 5, 3, 2, 12 }, staff, mage_bmp},
};

  /*
   *       case 0:
      statSeed = { 13, 13, 6, 6, 2 };
      name = "warrior";
      hp = getStat(statSeed.totalHP);
      bmp = warrior_bmp;
      inv[0] = sword;
      equiptedWpn = inv[0];
      break;

      case 1:
      name = "Tank";
      bmp = tank_bmp; 
      statSeed = { 20, 5, 10, 2, 3 };
      hp = getStat(statSeed.totalHP);
      inv[0] = sheild;
      equiptedWpn = inv[0];
      break;

      case 2:
      name = "mage";
      bmp = mage_bmp;
      statSeed = { 8, 5, 3, 2, 12 };
      hp = getStat(statSeed.totalHP);
      inv[0] = staff;
      equiptedWpn = inv[0];
      break;
   */



#endif // player_h

