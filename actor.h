#ifndef actor_h
#define actor_h

#include "Globals.h"

struct equpment {
  uint16_t atkMod;
  uint16_t defMod;
  uint16_t spcMod;
  const char* name;
  uint16_t cost;
};

struct baseStats {
  
  uint16_t totalHP;
  uint16_t strength;
  uint16_t defense;
  uint16_t speed;
  uint16_t special;
  
};


class actor {
  
  public:
  const char* name;
  int hp;
  byte* bmp;
  uint16_t level;
  equpment weapon;
  baseStats statSeed;


   explicit actor();
  // pickClass(uint16_t type);
   
   damage();
   takeDamage(actor attacker, uint16_t x);
   takeSpecial(actor attacker);
   levelUp();
   getStat (uint16_t stat);


};

  //class warrior: public actor {
  //public:
  //equpment weapon;
  
//};

//class tank: public actor {
 // equpment weapon;
  
//};

//class mage: public actor {
  //equpment weapon;
  
//};

#endif actor_h



