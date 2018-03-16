#include "enemy.h"
#include "images.h"

enemy::enemy(char* nm, equpment wpn, baseStats seed, byte sprite){
  name = nm;
  hp = getStat(seed.totalHP);
  bmp = sprite;
  equpment weapon = wpn;
  level = 1;
  baseStats statSeed = seed;

  
}

