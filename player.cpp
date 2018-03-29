#include "player.h"
#include "images.h"


playerCharacter::playerCharacter(): actor() {
  wallet = 100;
  level = 1;
  potion = 0;
  ex = 0;
  for (uint8_t x = 0; x < 5; ++x) {
    inv[x] = empty;
  }
  
}

void playerCharacter::printStats() {

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
      arduboy.println(getStat(statSeed.strength) + pgm_read_word(&weaponArray[static_cast<uint8_t>(equiptedWpn)].atkMod));
      arduboy.print(F("Defense:"));
      arduboy.println(getStat(statSeed.defense) + pgm_read_word(&weaponArray[static_cast<uint8_t>(equiptedWpn)].defMod));
      arduboy.print(F("Speed:"));
      arduboy.println(getStat(statSeed.speed));
      arduboy.print(F("Magic:"));
      arduboy.println(getStat(statSeed.special) + pgm_read_word(&weaponArray[static_cast<uint8_t>(equiptedWpn)].spcMod));
      arduboy.setCursor(75, 12);
      arduboy.print(F("Lvl:"));
      arduboy.print(level);
      arduboy.print(F(" "));
      //arduboy.print(ex);
      arduboy.setCursor(75, 20);
      arduboy.println(FlashString(pgm_read_word(&weaponArray[static_cast<uint8_t>(equiptedWpn)].name)));
      arduboy.setCursor(75, 28);
      arduboy.print(F("Coins:"));
      arduboy.print(wallet);
      arduboy.drawBitmap(100, 40, bmp, 20, 20, WHITE);
      if (potion == 1){
        arduboy.drawBitmap( 80, 40, potion_bmp, 8,8, WHITE);
      }
      else if (potion == 2){
        arduboy.drawBitmap( 80, 40, potion_bmp, 8,8, WHITE);
        arduboy.drawBitmap( 80, 50, potion_bmp, 8,8, WHITE);
      }
      
    
    }else if (menuCase == 1){
      arduboy.clear();
      arduboy.setCursor(0, 0);
      arduboy.print(F("INVENTORY ^STATS"));
      arduboy.drawLine(0, 10, 130, 10, WHITE);
      arduboy.setCursor(0, 12);
      printInv();
    }
}

void playerCharacter::equipt(uint16_t inventoryLocation){
 // weapon = { inventory[inventoryLocation].atkMod, inventory[inventoryLocation].defMod, inventory[inventoryLocation].spcMod, inventory[inventoryLocation].name, 0 };
 equiptedWpn = inv[inventoryLocation];
}

void playerCharacter::printInv(){
  //pgm_read_word(&weaponArray[static_cast<uint8_t>(storeInventory[0])].cost);
     for( uint16_t x = 0; x < 5 ; x++){
        arduboy.print(FlashString(pgm_read_word(&weaponArray[static_cast<uint8_t>(inv[x])].name)));
        arduboy.print(F(" a:"));
        arduboy.print(pgm_read_word(&weaponArray[static_cast<uint8_t>(inv[x])].atkMod));
        arduboy.print(F(" d:"));
        arduboy.print(pgm_read_word(&weaponArray[static_cast<uint8_t>(inv[x])].defMod));
        arduboy.print(F(" s:"));
        arduboy.println(pgm_read_word(&weaponArray[static_cast<uint8_t>(inv[x])].spcMod));
     }
}

void playerCharacter::pickClass(uint16_t type){
 
    switch(type){
      case 0:
      statSeed = { 13, 13, 6, 6, 2 };
      name = "warrior";
      hp = getStat(statSeed.totalHP);
      bmp = warrior_bmp;
      inv[0] = sword;
      equiptedWpn = inv[0];
      break;

      case 1:
      name = "Tank";
      bmp = tank_bmp; 
      statSeed = { 20, 5, 10, 2, 3 };
      hp = getStat(statSeed.totalHP);
      inv[0] = sheild;
      equiptedWpn = inv[0];
      break;

      case 2:
      name = "mage";
      bmp = mage_bmp;
      statSeed = { 8, 5, 3, 2, 12 };
      hp = getStat(statSeed.totalHP);
      inv[0] = staff;
      equiptedWpn = inv[0];
      break;
    }
 }

//exp to level up
//3*(B1^2)

void playerCharacter::checkLvlUp(){
  int expBarrier = (3*pow(level, 2))+4;
  if (ex >expBarrier){
    level++;
  }
}

//restores half of your health
void playerCharacter::usePotion(){
  potion--;
  if( hp < (getStat(statSeed.totalHP)/2)){ 
    hp += (getStat(statSeed.totalHP)/2);
  }
  else{
    hp = getStat(statSeed.totalHP);
  }
}

