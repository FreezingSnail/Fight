#include "actor.h"


actor::actor()  {
  
  hp;
  mp;
  equiptedWpn;
  level=1;
  type;
}
  
 
 
//return half of strength stat
uint16_t actor::damage(){
    return ((getStat(pgm_read_word(&type->statSeed.strength)) / 2)+pgm_read_word(&weaponArray[static_cast<uint8_t>(equiptedWpn)].atkMod));
}



//need to fix weapon modifiers
void actor::takeDamage(uint16_t damage, uint16_t modifier){
  
     int damageval = (((damage) - ((getStat(pgm_read_word(&type->statSeed.defense)))/2)-pgm_read_word(&weaponArray[static_cast<uint8_t>(equiptedWpn)].defMod)) - modifier);
      if (damageval > 0){
        hp -= damageval;
      }
      else{
        hp -= 1;
      }
}

void actor::takeSpecial(actor attacker){
  
  int damageval = (((getStat(pgm_read_word(pgm_read_word(&attacker.type->statSeed.special))))/2)/*+weapon.spcMod*/-((getStat(pgm_read_word(&type->statSeed.special)))/2)/*-weapon.spcMod*/) ;
      if (damageval > 0){
        hp -= damageval;
      }
      else{
      }
}


void actor::levelUp(){
  level++;
  hp = getStat(pgm_read_word(&type->statSeed.totalHP));
  
  
}

uint16_t actor::getStat(uint8_t stat){
  //=(((3 * B1))/4)+1
  return ((((stat* level)/4)) +level);
  
}


uint16_t actor::expDrop(){
  return level*2;
}

//warrior::warrior{
  //weapon sword(1, 0, "sword");
//}


  

//damage formula
// ((strength/2)+ weapon atk) - ((def/2) +weapon def mod) + modifier
//ie if opponet defends mod = -2

