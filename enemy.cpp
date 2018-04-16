#include "enemy.h"
#include "actor.h"

enemy::enemy( uint8_t lvl, const actorType & typeActor){
  level = lvl;
  type = &typeActor;
  hp = getStat(pgm_read_word(type->statSeed.totalHP));
  equiptedWpn = (pgm_read_word(&type->weapon));
  mp = hp/2;
}



