#ifndef player_h
#define player_h
#include "actor.h"
#include "weapons.h"

class playerCharacter: public actor{
  
public:
  playerCharacter();
  int wallet;
  weaponId equiptedWpn;
  weaponId inv[5]; //= {InvSlot1, InvSlot2, InvSlot3, InvSlot4, InvSlot5};
  int ex;
  int arenalvl;
  int potion;

  void printInv();
  void printStats();
  void equipt(uint16_t inventoryLocation);
  void pickClass(uint16_t x);
  void checkLvlUp();
  void usePotion();
  
};



#endif // player_h

