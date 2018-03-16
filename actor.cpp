#include "actor.h"
#include "images.h"
#include "names.h"


actor::actor() {
  
  name;
  hp;
  bmp;
  equpment weapon;
  level = 1;
  baseStats statSeed;
}
  
 

 
actor::damage(){
    return (getStat(statSeed.strength) / 3);
}

actor::takeDamage(actor attacker, uint16_t modifier){
  
     int damageval = (((attacker.damage())+attacker.weapon.atkMod) - ((getStat(statSeed.defense)/2)-weapon.defMod) - modifier);
      if (damageval > 0){
        hp -= damageval;
      }
      else{
        hp -= 1;
      }
}


actor::takeSpecial(actor attacker){
  
  int damageval = ((getStat(attacker.statSeed.special))+weapon.spcMod);
      if (damageval > 0){
        hp -= damageval;
      }
      else{
      }
}

actor::levelUp(){
  level++;
  hp = statSeed.totalHP;

  
  
}

actor::getStat(uint16_t stat){
  //(((10*2) * ((B1^2)/2)- 2))/2
  return ((((stat*2)*(pow(level, 2)/2)) -2)/2)+1;
  
}

//warrior::warrior{
  //weapon sword(1, 0, "sword");
//}


  

//damage formula
// ((strength/2)+ weapon atk) - ((def/2) +weapon def mod) + modifier
//ie if opponet defends mod = -2

