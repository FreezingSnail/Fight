#include "actor.h"
#include "images.h"


actor::actor(char* nm, byte BMP, equpment Item) {
  
  name = nm;
  hp;
  bmp;
  weapon;
  level = 1;
  baseStats statSeed;
}
  
 




actor::pickClass(uint16_t type){
 
    switch(type){
      case 0:
      statSeed = {10, 10, 5, 5, 1};
      name = "warrior";
      hp = getStat(statSeed.totalHP);
      bmp = warrior_bmp;
      //inventory[0] = {1, 0, 0, "Sword"};
      weapon = {1, 0, 0, "Sword"};
     
      break;

      case 1:
      name = "Tank";
      //inventory[0] = {0, 1, 0, "Sheild"};
      weapon = {0, 1, 0, "Sheild"};
      bmp = tank_bmp; 
      statSeed = {20, 5, 5, 10, 1};
      hp = getStat(statSeed.totalHP);
      break;

      case 2:
      name = "mage";
      bmp = mage_bmp;
      //inventory[0] = {0, 0, 1, "Staff"};
      weapon = {0, 0, 1, "Staff"};
      statSeed = {10, 1, 1, 10, 10};
      hp = getStat(statSeed.totalHP);
      break;
    }
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

