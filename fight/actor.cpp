#include "actor.h"
#include "images.h"



actor::actor(char* nm, int h, int str, int def, int spd, int spc) {
  
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

  for (int x; x<5; x++){
    inventory[x] = {0, 0, "EMPTY"};
  } 
}
  
 
actor::printStats() {
    
    if( menuNum == 0){
    
      arduboy.setCursor(0, 12);
      arduboy.println(name);
      arduboy.print(hp);
      arduboy.print(" / ");
      arduboy.print(totalHP);
      arduboy.println(" HP ");
      arduboy.print("Strength:");
      arduboy.println(strength);
      arduboy.print("Defense:");
      arduboy.println(defense);
      arduboy.print("Speed:");
      arduboy.println(speed);
      arduboy.print("Magic:");
      arduboy.println(special);
      arduboy.setCursor(75, 12);
      arduboy.println(weapon.name);
      arduboy.setCursor(75, 20);
      arduboy.print("str:");
      arduboy.print(weapon.atkMod);
      arduboy.setCursor(75, 30);
      arduboy.print("def:");
      arduboy.print(weapon.defMod);
      arduboy.setCursor(50, 52);
      arduboy.print("Coins:");
      arduboy.print(wallet);
      arduboy.drawBitmap(100, 40, bmp, 20, 20, WHITE);
      
    
      if(arduboy.pressed(DOWN_BUTTON)) {
        menuNum = 1;
      }
      
      if( arduboy.notPressed(DOWN_BUTTON) == true ) {
        downbuff = 0;
      }
    
    }else if (menuNum == 1){
      arduboy.clear();
      arduboy.setCursor(0, 0);
      arduboy.print("INVENTORY ^STATS");
      arduboy.drawLine(0, 10, 130, 10, WHITE);
      arduboy.setCursor(0, 12);
      printInv();

      if(arduboy.pressed(UP_BUTTON)){
        menuNum = 0;
      }
     
      if( arduboy.notPressed(UP_BUTTON) == true ) {
        upbuff = 0;
      }
    }
}

actor::equipt(int inventoryLocation){
  weapon = {inventory[inventoryLocation].atkMod, inventory[inventoryLocation].defMod, inventory[inventoryLocation].name};
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
      inventory[0] = {1, 0, "sword"};
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
      inventory[0] = {0, 1, "Sheild"};
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
      inventory[0] = {1, 0, "Staff"};
      weapon = inventory[0];
      break;
    }
 }
 
actor::damage(){
    return (strength / 2);
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
        arduboy.println(inventory[x].name);
     }
}

//warrior::warrior{
  //weapon sword(1, 0, "sword");
//}


  

//damage formula
// ((strength/2)+ weapon atk) - ((def/2) +weapon def mod) + modifier
//ie if opponet defends mod = -2

