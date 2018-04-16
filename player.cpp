#include "player.h"


playerCharacter::playerCharacter(const actorType & typeActor): actor() {
  wallet = 100;
  level = 1;
  potion = 0;
  ex = 0;
  type = &typeActor;
  hp = getStat(pgm_read_word(&type->statSeed.totalHP));
  equiptedWpn = (pgm_read_word(&type->weapon));
  mp = hp/2;

  for (uint8_t x = 0; x < 5; ++x) {
    inv[x] = empty;
  }
  inv[0] = (pgm_read_word(&type->weapon));
  
}

void playerCharacter::printStats() {

    if (menuCase > 1){ menuCase = 0;}
    if (menuCase < 0){menuCase = 1;} 
    
    if( menuCase == 0){
    
      arduboy.setCursor(0, 12);
      arduboy.println(FlashString(pgm_read_word(&type->name)));
      arduboy.print(hp);
      arduboy.print(" / ");
      arduboy.print(getStat(pgm_read_word(&type->statSeed.totalHP)));
      arduboy.println(F(" HP "));
      arduboy.print(F("Strength:"));
      arduboy.println(getStat(pgm_read_word(&type->statSeed.strength)) + pgm_read_word(&weaponArray[static_cast<uint8_t>(equiptedWpn)].atkMod));
      arduboy.print(F("Defense:"));
      arduboy.println(getStat(pgm_read_word(&type->statSeed.defense)) + pgm_read_word(&weaponArray[static_cast<uint8_t>(equiptedWpn)].defMod));
      arduboy.print(F("Speed:"));
      arduboy.println(getStat(pgm_read_word(&type->statSeed.speed)));
      arduboy.print(F("Magic:"));
      arduboy.println(/*getStat(pgm_read_word(&type->statSeed.special)) +*/ pgm_read_word(&weaponArray[static_cast<uint8_t>(equiptedWpn)].spcMod));
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
      arduboy.drawBitmap(100, 40, pgm_read_word(&type->bmp), 20, 20, WHITE);
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
 equiptedWpn = inv[inventoryLocation];
}

void playerCharacter::printInv(){
  //pgm_read_word(&weaponArray[static_cast<uint8_t>(storeInventory[0])].cost);
     for( uint8_t x = 0; x < 5 ; x++){
        arduboy.print(FlashString(pgm_read_word(&weaponArray[static_cast<uint8_t>(inv[x])].name)));
        arduboy.print(F(" a:"));
        arduboy.print(pgm_read_word(&weaponArray[static_cast<uint8_t>(inv[x])].atkMod));
        arduboy.print(F(" d:"));
        arduboy.print(pgm_read_word(&weaponArray[static_cast<uint8_t>(inv[x])].defMod));
        arduboy.print(F(" s:"));
        arduboy.println(pgm_read_word(&weaponArray[static_cast<uint8_t>(inv[x])].spcMod));
     }
}



void playerCharacter::printMoves(){
  
  for( uint8_t x = 0; x < (pgm_read_word(&type->attackListLength)); x++){
    arduboy.println(FlashString(pgm_read_word(&spellIndex[static_cast<uint8_t>(type->attackList[x])].name)));  
  }
  for( uint8_t x = 0; x < (pgm_read_word(&type->spellListLength)); x++){
    arduboy.println(FlashString(pgm_read_word(&spellIndex[static_cast<uint8_t>(type->spellList[x])].name)));
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
  if( hp < ((getStat(pgm_read_word(&type->statSeed.totalHP)))/2)){ 
    hp += (getStat(pgm_read_word(&type->statSeed.totalHP)))/2;
  }
  else{
    hp = getStat(pgm_read_word(&type->statSeed.totalHP));
  }
}

