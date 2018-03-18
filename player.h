#ifndef player_h
#define player_h
#include "actor.h"

class playerCharacter: public actor{
  
public:
  playerCharacter();
  int wallet;
  equpment weapon;
  equpment inventory[5];
  int ex;
  int arenalvl;
  int potion;

   printInv();
   printStats();
   equipt(uint16_t inventoryLocation);
   pickClass(uint16_t x);
   checkLvlUp();
   usePotion();
  
};



#endif player_h

