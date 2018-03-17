#include "enemy.h"
#include "images.h"

enemy::enemy(char* nm, equpment wpn, baseStats seed, byte sprite, int lvl){
  name = nm;
  hp = getStat(seed.totalHP);
  bmp = sprite;
  equpment weapon = wpn;
  level = lvl;
  baseStats statSeed = seed;
}




