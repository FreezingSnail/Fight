#include "actor.h"
#include "images.h"



actor::actor(char* nm, int h, int str, int def, int spd, int spc, byte BMP, equpment Item) {
  
  name = nm;
  totalHP = h;
  hp = h;
  strength = str;
  defense = def;
  speed = spd;
  special = spc;
  bmp;
  weapon;
  wallet = 0;
  inventory[5];
  level = 0;

  for (int x; x<5; x++){
    inventory[x] = {0, 0, 0, "EMPTY"};
  } 
}
  
 
actor::printStats() {

    if (menuCase > 1){ menuCase = 0;}
    if (menuCase < 0){menuCase = 1;} 
    
    if( menuCase == 0){
    
      arduboy.setCursor(0, 12);
      arduboy.println(name);
      arduboy.print(hp);
      arduboy.print(" / ");
      arduboy.print(totalHP);
      arduboy.println(" HP ");
      arduboy.print("Strength:");
      arduboy.println(strength + weapon.atkMod);
      arduboy.print("Defense:");
      arduboy.println(defense + weapon.defMod);
      arduboy.print("Speed:");
      arduboy.println(speed);
      arduboy.print("Magic:");
      arduboy.println(special + weapon.spcMod);
      arduboy.setCursor(75, 12);
      arduboy.print("Lvl:");
      arduboy.print(level);
      arduboy.setCursor(75, 20);
      arduboy.println(weapon.name);
      arduboy.setCursor(75, 28);
      arduboy.print("Coins:");
      arduboy.print(wallet);
      arduboy.drawBitmap(100, 40, bmp, 20, 20, WHITE);
      
    
    }else if (menuCase == 1){
      arduboy.clear();
      arduboy.setCursor(0, 0);
      arduboy.print("INVENTORY ^STATS");
      arduboy.drawLine(0, 10, 130, 10, WHITE);
      arduboy.setCursor(0, 12);
      printInv();
    }
}

actor::equipt(int inventoryLocation){
  weapon = {inventory[inventoryLocation].atkMod, inventory[inventoryLocation].defMod, inventory[inventoryLocation].spcMod, inventory[inventoryLocation].name};
}



actor::pickClass(int type){
 
    switch(type){
      case 0:
      name = "warrior";
      hp = 10;
      totalHP = 10;
      strength = 10;
      defense = 5;
      speed = 5;
      special = 0;
      bmp = warrior_bmp;
      inventory[0] = {1, 0, 0, "Sword"};
      weapon = inventory[0];
      break;

      case 1:
      name = "Tank";
      hp = 20;
      totalHP = 20;
      strength = 5;
      defense = 10;
      speed = 0;
      special = 5;
      bmp = tank_bmp;
      inventory[0] = {0, 1, 0, "Sheild"};
      weapon = inventory[0];
      break;

      case 2:
      name = "mage";
      hp = 10;
      totalHP = 10;
      strength = 0;
      defense = 0;
      speed = 10;
      special = 10;
      bmp = mage_bmp;
      inventory[0] = {0, 0, 1, "Staff"};
      weapon = inventory[0];
      break;
    }
 }
 
actor::damage(){
    return (strength / 3);
}

actor::takeDamage(actor attacker, int modifier){
  
      int damageval = (((attacker.damage())+attacker.weapon.atkMod) - ((defense/5)-weapon.defMod) - modifier);
      if (damageval > 0){
        hp -= damageval;
      }
      else{
        hp -= 1;
      }
}

actor::printInv(){
     for( int x = 0; x < 5 ; x++){
        arduboy.print(inventory[x].name);
        arduboy.print(" a:");
        arduboy.print(inventory[x].atkMod);
        arduboy.print(" d:");
        arduboy.print(inventory[x].defMod);
        arduboy.print(" s:");
        arduboy.println(inventory[x].spcMod);
     }
}

actor::takeSpecial(actor attacker){
  
  int damageval = ((attacker.special/2)+weapon.spcMod);
      if (damageval > 0){
        hp -= damageval;
      }
      else{
      }
}

actor::levelUp(){
  level++;
  totalHP += 5;
  hp = totalHP;
  strength += (strength/3) +1;
  defense += (defense/3) +1;
  speed += (speed/3) +1;
  special += (special/3) +1;
  
  
}

//warrior::warrior{
  //weapon sword(1, 0, "sword");
//}


  

//damage formula
// ((strength/2)+ weapon atk) - ((def/2) +weapon def mod) + modifier
//ie if opponet defends mod = -2

