#include "player.h"

playerCharacter::playerCharacter(char* nm, byte BMP, equpment Item): actor(nm, BMP, Item) {
  wallet = 0;
  inventory[5];
  for (uint16_t x; x<5; x++){
    inventory[x] = {0, 0, 0, "EMPTY"};
  } 
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
      arduboy.println(" HP ");
      arduboy.print("Strength:");
      arduboy.println(getStat(statSeed.strength) + weapon.atkMod);
      arduboy.print("Defense:");
      arduboy.println(getStat(statSeed.defense) + weapon.defMod);
      arduboy.print("Speed:");
      arduboy.println(getStat(statSeed.speed));
      arduboy.print("Magic:");
      arduboy.println(getStat(statSeed.special) + weapon.spcMod);
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

playerCharacter::equipt(uint16_t inventoryLocation){
  weapon = {inventory[inventoryLocation].atkMod, inventory[inventoryLocation].defMod, inventory[inventoryLocation].spcMod, inventory[inventoryLocation].name};
}

playerCharacter::printInv(){
     for( uint16_t x = 0; x < 5 ; x++){
        arduboy.print(inventory[x].name);
        arduboy.print(" a:");
        arduboy.print(inventory[x].atkMod);
        arduboy.print(" d:");
        arduboy.print(inventory[x].defMod);
        arduboy.print(" s:");
        arduboy.println(inventory[x].spcMod);
     }
}


