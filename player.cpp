#include "player.h"
#include "images.h"
#include "names.h"


playerCharacter::playerCharacter(): actor() {
  wallet = 100;
  //weapon = {1, 0, 0, "debug"};
  inventory[5];
  for (uint16_t x; x<5; x++){
    inventory[x] = {0, 0, 0, "EMPTY"};
  } 

  inventory[0] = weapon;
}

playerCharacter::printStats() {

    if (menuCase > 1){ menuCase = 0;}
    if (menuCase < 0){menuCase = 1;} 
    
    if( menuCase == 0){
    
      arduboy.setCursor(0, 12);
      arduboy.println(name);
      arduboy.print(hp);
      arduboy.print(" / ");
      arduboy.print(getStat(statSeed.totalHP));
      arduboy.println(F(" HP "));
      arduboy.print(F("Strength:"));
      arduboy.println(getStat(statSeed.strength) + weapon.atkMod);
      arduboy.print(F("Defense:"));
      arduboy.println(getStat(statSeed.defense) + weapon.defMod);
      arduboy.print(F("Speed:"));
      arduboy.println(getStat(statSeed.speed));
      arduboy.print(F("Magic:"));
      arduboy.println(getStat(statSeed.special) + weapon.spcMod);
      arduboy.setCursor(75, 12);
      arduboy.print(F("Lvl:"));
      arduboy.print(level);
      arduboy.setCursor(75, 20);
      arduboy.println(weapon.name);
      arduboy.setCursor(75, 28);
      arduboy.print(F("Coins:"));
      arduboy.print(wallet);
      arduboy.drawBitmap(100, 40, bmp, 20, 20, WHITE);
      
    
    }else if (menuCase == 1){
      arduboy.clear();
      arduboy.setCursor(0, 0);
      arduboy.print(F("INVENTORY ^STATS"));
      arduboy.drawLine(0, 10, 130, 10, WHITE);
      arduboy.setCursor(0, 12);
      printInv();
    }
}

playerCharacter::equipt(uint16_t inventoryLocation){
  weapon = {inventory[inventoryLocation].atkMod, inventory[inventoryLocation].defMod, inventory[inventoryLocation].spcMod, inventory[inventoryLocation].name};
}

playerCharacter::printInv(){
     for( uint16_t x = 0; x < 5 ; x++){
        arduboy.print(inventory[x].name);
        arduboy.print(F(" a:"));
        arduboy.print(inventory[x].atkMod);
        arduboy.print(F(" d:"));
        arduboy.print(inventory[x].defMod);
        arduboy.print(F(" s:"));
        arduboy.println(inventory[x].spcMod);
     }
}

playerCharacter::pickClass(uint16_t type){
 
    switch(type){
      case 0:
      statSeed = {10, 10, 5, 5, 1};
      name = "warrior";
      hp = getStat(statSeed.totalHP);
      bmp = warrior_bmp;
      inventory[0] = {1, 0, 0, "Sword", 0};
      weapon = inventory[0];
      break;

      case 1:
      name = "Tank";
      //inventory[0] = {0, 1, 0, "Sheild"};
      weapon = {0, 1, 0, "Sheild", 0};
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
  

