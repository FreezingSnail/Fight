#ifndef enemy_h
#define enemy_h
#include "actor.h"

class enemy: public actor{
  
public:
  enemy(char* nm, equpment wpn, baseStats seed, byte sprite, int lvl);

  setMob(char* nm, equpment wpn, baseStats seed, byte sprite, int lvl);


};


#endif enemy_h

