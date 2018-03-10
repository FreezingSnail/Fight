#ifndef player_h
#define player_h
#include "actor.h"

class playerCharacter: public actor{
  
public:
  playerCharacter(char* nm, byte BMP, equpment Item);
  int wallet;
  equpment weapon;
  equpment inventory[5];

   printInv();
   printStats();
   equipt(uint16_t inventoryLocation);
  
};



#endif player_h

