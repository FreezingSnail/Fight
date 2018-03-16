#ifndef player_h
#define player_h
#include "actor.h"

class playerCharacter: public actor{
  
public:
  playerCharacter();
  int wallet;
  equpment weapon;
  equpment inventory[5];

   printInv();
   printStats();
   equipt(uint16_t inventoryLocation);
   pickClass(uint16_t x);
  
};



#endif player_h

