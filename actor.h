#ifndef actor_h
#define actor_h

#include "Globals.h"
#include "weapons.h"
#include "images.h"
#include "attacks.h"




struct baseStats {
  
  uint16_t totalHP;
  uint16_t strength;
  uint16_t defense;
  uint16_t speed;
  uint16_t special;
  
};

struct actorType {
  const char* name;
  baseStats statSeed;
  weaponId weapon;
  const byte* bmp;
   spellNames spellList[4];
   spellNames attackList[4];
   uint16_t spellListLength;
   uint16_t attackListLength;
  
};


class actor {
  
  public:
  int hp;
  int mp;
  uint8_t level;
  weaponId equiptedWpn;
  const actorType * type;



   actor();
  // pickClass(uint16_t type);
   
   uint16_t damage();

   void takeDamage(uint16_t damage, uint16_t modifier);

   void takeSpecial(actor attacker);

   void levelUp();
   uint16_t getStat (uint8_t stat);

   uint16_t expDrop();



};


#endif // actor_h



