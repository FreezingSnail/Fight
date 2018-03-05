#include "gameEngine.h"
#include "Globals.h"
#include "actor.h"
#include "fightEngine.h"
#include "images.h"

//INITIALIZE ACTORS
actor player = actor("null", 0, 0, 0, 0, 0);
actor enemy = actor("null", 0, 0, 0, 0, 0);

//STORE INVENTORY ARRAY
const equpment storeInventory[] = {{2, 0, "Kleaver", 10}, {0, 2, "Broad Shield", 10}, {10, 2, "Katana", 20}}; 



//OTHER INTS FOR MENU LOCATIONS
int upbuff = 0;
int downbuff = 0;
int abuff = 0;
int equiptMenu = 0;
bool infight = false;
int itemSelected;

//CHARACTER SELECTION
void gameStart(){
  player = actor("null", 0, 0, 0, 0, 0);
  arduboy.clear();
  arduboy.setCursor(0, 0);
  arduboy.print("Pick your class.");
  arduboy.print("\n");
  arduboy.drawLine(0, 10, 130, 10, WHITE);
  arduboy.setCursor(0, 12);

    
    if (menuCase > 2){ menuCase = 0;}
    if (menuCase < 0){ menuCase = 2;} 

    switch (menuCase) {

      case 0:
      arduboy.println("Warrior");
      arduboy.drawBitmap(0, 30, warrior_bmp, 20, 20, WHITE);
      arduboy.print("Strong Attack");
      
      break;
      case 1:
      arduboy.println("Tank");
      arduboy.drawBitmap(0, 30, tank_bmp, 20, 20, WHITE);
      arduboy.print("High Health & Defense");
      break;
      case 2:
      arduboy.println("Mage");
      arduboy.drawBitmap(0, 30, mage_bmp, 20, 20, WHITE);
      arduboy.print("Fast and frail");
      break;
  
    }


   if( arduboy.pressed(A_BUTTON) == true and abuff ==0){
      abuff = 1;
      switch (menuCase) {

      case 0:
      player.pickClass(0);
      menuCase = 0;
      gameStatus = menu;
      break;
      case 1:
      player.pickClass(1);
      menuCase = 0;
      gameStatus = menu;
      break;
      case 2:
      player.pickClass(2);
      menuCase = 0;
      gameStatus = menu;
      break;
    }
 
  }

}


//INTRO SCREEN
void  Intro(){
  arduboy.clear();
  //arduboy.drawBitmap(0, 0, splashScreen, 128, 64, WHITE);
  //ADD GAME SPLASH SCREEN
  arduboy.setCursor(25, 0);
  arduboy.print("Hit b to start");
  //ADD HELP SCREEN
  if (arduboy.pressed(B_BUTTON)){
    gameStatus = charSelect;
    menuCase = 0;
  }
}

//MAIN MENU AND ROOM SELECTION
void MainMenu() {
  
  arduboy.clear();
  arduboy.setCursor(0, 0);
  arduboy.print("MAIN MENU");
  arduboy.drawLine(0, 10, 130, 10, WHITE);
  arduboy.setCursor(0, 12);
  
    if (menuCase > 3){ menuCase = 0;}
    if (menuCase < 0){menuCase = 3;} 

    switch (menuCase) {

      case 0:
      arduboy.print("stats");
      break;
      case 1:
      if( player.hp > 0){
        arduboy.print("battle");
      }
      else {
        arduboy.println("You are fainted");
        arduboy.print("You cannot fight");
      }
      break;
      case 2:
      arduboy.print("quit");
      break;
      // case 3:
      //arduboy.print("case 3");
      //break;
      case 3:
      arduboy.print("store");
      break;
    }


   if( arduboy.pressed(A_BUTTON) == true and abuff ==0){
      abuff = 1;
      switch (menuCase) {

      case 0:
      gameStatus = statScreen;
      menuNum = 0;
      break;
      case 1:
      if( player.hp > 0){
        gameStatus = battle;
      }
      
      break;
      case 2:
      setup();
      break;
      //case 3:
      
      //break;
      case 3:
      gameStatus = store;
      menuCase = 0;
      menuNum = 0;
      break;
    }
    }


}

//INITIALIZE FIGHT ROOM 
void fight() {
  
    if(infight == false){
      arduboy.clear();
      int x = rand() %3;
      enemy.pickClass(x);
      infight = true;
      menuCase = 0;
    }
  //RUN BATTLE
    BattleScene(); 
  
  
  
}


//PRINT PLAYER STATS AND MANAGE INVENTORY
void  StatMenu() {
    arduboy.clear();
    arduboy.setCursor(0, 0);
    arduboy.print("STATS v-INV >EQPT");
    arduboy.drawLine(0, 10, 130, 10, WHITE);

    if(arduboy.pressed(B_BUTTON)) {
    gameStatus = menu;
    }

    if(equiptMenu == 0){
      player.printStats();

    if(arduboy.pressed(RIGHT_BUTTON)) {
      equiptMenu =1;
      menuCase =0;
    }
  }

  if (equiptMenu == 1){
    arduboy.clear();
    arduboy.setCursor(0, 0);
    arduboy.print("<STATS ");
    arduboy.drawLine(0, 10, 130, 10, WHITE);
    arduboy.setCursor(0, 12);
    arduboy.println("Select item to equipt");
    
      if (menuCase > 4){ menuCase = 0;}
      if (menuCase < 0){menuCase = 4;} 
      arduboy.print(player.inventory[menuCase].name);
      
      if( arduboy.pressed(A_BUTTON) == true and abuff ==0){
          player.equipt(menuCase);
          equiptMenu = 0;

      }    
    
      if(arduboy.pressed(LEFT_BUTTON)) {
        equiptMenu =0;
      }
  }
}

//END SCREEN PAUSE FOR FIGHTS
//ADD LOOT/MONEY/DROPPED ITEMS/ ETC
void VictoryScreen(){
  arduboy.clear();
  arduboy.setCursor(40, 20);
  arduboy.println("Victory");
  arduboy.println("take 2 coins");
  arduboy.println("as your prize");
  arduboy.print("B to return to menu");

  //add bonuses

  if (arduboy.pressed(B_BUTTON)){

    gameStatus = menu;
    infight = false; 
    player.wallet += 2;
  }
}

//death screen
void FailScreen(){
  arduboy.clear();
  arduboy.setCursor(2, 20);
  arduboy.println(F("You have Failed"));
  arduboy.println("B to return to menu");

  if(player.wallet <= 0){
    arduboy.println("The Arena Pitties you");
    arduboy.println("Take a coin to heal");
    
  }
  //Add Repercussions

  if (arduboy.pressed(B_BUTTON)){
    
      gameStatus = menu;
      infight = false; 
      player.hp = 0;
      if(player.wallet <= 0){
      player.wallet +=1;
    }
  }
}

//FIGHT LOOP
void BattleScene() {
 if (player.hp >0){
  if (enemy.hp >0){
    arduboy.clear();
    arduboy.setCursor(0, 0);
    arduboy.print(enemy.name);
    arduboy.print(" hp: ");
    arduboy.println(enemy.hp);
    arduboy.drawLine(0, 10, 65, 10, WHITE);
    arduboy.setCursor(60, 52);
    arduboy.print(player.hp);
    arduboy.print(" / ");
    arduboy.print(player.totalHP);
    arduboy.print(" HP");
    arduboy.drawLine(58, 62, 120, 62, WHITE);

    arduboy.drawBitmap(85, 0, enemy.bmp, 20, 20, WHITE);
    arduboy.drawBitmap(8, 29, player.bmp, 20, 20, WHITE);
    arduboy.setCursor(0, 50);
    Engagement(player, enemy);

 
  }
  else {
    VictoryScreen();
  }
 }
 else{
  FailScreen();
 }
}

//PURCHASE EQUIPTMENT/HEAL
void Store() {

  arduboy.clear();
  arduboy.setCursor(0, 0);
  arduboy.print("Store");
  arduboy.drawLine(0, 10, 130, 10, WHITE);
  arduboy.setCursor(0, 12);

  //scroll menu


    if(arduboy.pressed(B_BUTTON)) {
    gameStatus = menu;
    menuCase = 0;
    }

    if(menuNum == 0){
    if (menuCase > 1){ menuCase = 0;}
    if (menuCase < 0){menuCase = 1;} 

    switch (menuCase) {

      case 0:
      arduboy.print("Buy new equiptment");
      break;
      case 1:
      if (player.hp < player.totalHP){
      arduboy.print("HEAL: 1 coin");
      }else{
        arduboy.print("You need not heal");
      }
      break;
   
    }

     if( arduboy.pressed(A_BUTTON) == true and abuff ==0){
      abuff = 1;
      switch (menuCase) {
       case 0:
      menuNum = 1;
      break;
      case 1:
      if(player.wallet > 0 && player.hp < player.totalHP){
      player.hp = player.totalHP;
      player.wallet -=1;
      }
      break;
      }
      
    }
   }

//display store inventory
  if(menuNum == 1){
    if (menuCase > 2){ menuCase = 0;}
    if (menuCase < 0){menuCase = 2;} 
   
    arduboy.clear();
    arduboy.print(storeInventory[menuCase].name);
    arduboy.print(" ");
    arduboy.print(storeInventory[menuCase].cost);
    arduboy.println(" coins");

    if (player.wallet < storeInventory[menuCase].cost){
      arduboy.print("you lack the coins");
    }

      if( arduboy.pressed(A_BUTTON) == true and abuff ==0 and player.wallet >= storeInventory[menuCase].cost){
        abuff = 1;
        itemSelected = menuCase;
        menuNum = 2;
      }
   }

//pick slot to place item   
  if(menuNum == 2){
    if (menuCase > 4){ menuCase = 0;}
    if (menuCase < 0){menuCase = 4;} 
  
    arduboy.clear();
    arduboy.println("select slot in inventory");
    arduboy.print("slot #: ");
    arduboy.print(menuCase);
    arduboy.print(" ");
    arduboy.println(player.inventory[menuCase].name);
    
    if( arduboy.pressed(A_BUTTON) == true and abuff ==0){
      player.inventory[menuCase] = storeInventory[itemSelected];
      player.wallet -= storeInventory[itemSelected].cost;
      menuNum = 0;
      abuff = 1;
    }  
  }
    
      
}


