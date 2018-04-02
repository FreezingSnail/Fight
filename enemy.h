#ifndef enemy_h
#define enemy_h
#include "actor.h"
#include "images.h"
#include "weapons.h"


struct mobType  {

  const char* name;
  baseStats statSeed;
  weaponId weapon;
  const byte* bmp;

  
};

class enemy: public actor{

  public:
    enemy(uint8_t lvl, const actorType & type);



};


const char PROGMEM mobNmKnight[] = "Knight";
const char PROGMEM mobNmTank[] = "Tank";
const char PROGMEM mobNmWarlock[] = "Warlock";
const char PROGMEM mobNmSpider[] = "Spider";
const char PROGMEM mobNmOrc[] = "Orc";
const char PROGMEM mobNmSlime[] = "Slime";
const char PROGMEM mobNmTroll[] = "Troll";
const char PROGMEM mobNmOgre[] = "Ogre";
const char PROGMEM mobNmMaster[] = "Master";


const  actorType mobList[] PROGMEM = {
  {mobNmKnight, {8, 8, 5, 4, 0}, sword, warrior_bmp, {}, {Swipe}},
  {mobNmTank, {10, 4, 7, 2, 2}, sheild, tank_bmp, {}, {Swipe}},
  {mobNmWarlock, {8, 1, 2, 8, 8}, staff, mage_bmp, {Fire, Water}, {Swipe}},
  {mobNmSpider, {5, 7, 4, 8, 1}, empty, spider_bmp, {}, {Swipe}},
  {mobNmOrc, {7, 8, 6, 1, 3}, club, orc_bmp, {}, {Bash}},
  {mobNmSlime, {28, 8, 10, 6, 8}, empty, slime_bmp, {}, {Swipe}},
  {mobNmTroll, {20, 15, 10, 7, 8}, club, troll_bmp, {Fire}, {Bash}},
  {mobNmOgre, {20, 20, 15, 5, 0}, empty, ogre_bmp, {Fire}, {Bash}},
  {mobNmMaster, {20, 15, 15, 10, 10}, empty, arenaMaster_bmp, {Cure}, {Swipe}},  
  
};

/*
  const char* name;
  baseStats statSeed;
  weaponId weapon;
  const byte* bmp;
 */

/*
      setMob("", sword, {8, 8, 5, 4, 0}, slime_bmp, moblvl);
      mob.name = "Knight";
      mob.bmp = warrior_bmp;

      setMob("", sheild, {10, 4, 7, 2, 2}, slime_bmp, moblvl);
      mob.name = "Tank";
      mob.bmp = tank_bmp;


      setMob("", staff, {8, 1, 2, 8, 8}, mage_bmp, moblvl);
      mob.name = "Warlock";
      mob.bmp = mage_bmp;

      setMob("", empty, {5, 7, 4, 8, 1}, mage_bmp, moblvl);
      mob.name = "Spider";
      mob.bmp = spider_bmp;



      setMob("", club, {7, 8, 6, 1, 3}, mage_bmp, moblvl);
      mob.name = "Orc";
      mob.bmp = orc_bmp;


      setMob("slime", club /*{3, 0, 3, "slime ball"}, {28, 8, 10, 6, 8}, slime_bmp, 3);
      //mob.statSeed = {25, 8, 8, 6, 8};
      //mob.name = "Slime";
      mob.bmp = slime_bmp;
      //mob.weapon = {3, 0, 3, "slime ball"};
      //mob.level = 3;

      setMob("troll", club /*{4, 2, 0, "Club"}, {20, 15, 10, 7, 8},  troll_bmp, 4);
      mob.bmp = troll_bmp;
      //mob.name = "Troll";
     // mob.level = 2;
   
      setMob("ogre", club /*{6, 0, 0, "Ogre Claws"}, {20, 20, 15, 5, 0}, ogre_bmp, 5);
      mob.bmp = ogre_bmp;
     // mob.name = "Ogre";

      setMob("Master", club /*{15, 0, 0, "Schimtar"}, {20, 15, 15, 10, 10}, ogre_bmp, 6);
      mob.bmp = arenaMaster_bmp;
     // mob.name = "Master";
*/
#endif // enemy_h

