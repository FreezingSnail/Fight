#ifndef actor_h
#define actor_h

#include "Globals.h"
#include "weapons.h"
#include "images.h"
#include "attacks.h"




struct baseStats {
  
  uint8_t totalHP;
  uint8_t strength;
  uint8_t defense;
  uint8_t speed;
  uint8_t special;
  
};

struct actorType {
  const char* name;
  baseStats statSeed;
  weaponId weapon;
  const byte* bmp;
  const spellNames spellList[4];
  const attackNames attackList[4];
  
};


class actor {
  
  public:
  int hp;
  int mp;
  uint8_t level;
  weaponId weapon;
  const actorType * type;



   actor();
  // pickClass(uint16_t type);
   
   uint16_t damage();

   void takeDamage(actor attacker, uint16_t x);

   void takeSpecial(actor attacker);

   void levelUp();
   uint16_t getStat (uint8_t stat);

   uint16_t expDrop();



};


#endif // actor_h



