#include "enemy.h"
#include "actor.h"

enemy::enemy( uint8_t lvl, const actorType & typeActor){
  level = lvl;
  type = &typeActor;
  hp = getStat(pgm_read_word(type->statSeed.totalHP));
  mp = hp/2;
}



