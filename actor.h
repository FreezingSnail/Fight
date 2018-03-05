#ifndef actor_h
#define actor_h

#include "Globals.h"

struct equpment {
  int atkMod;
  int defMod;
  int spcMod;
  char* name;
  int cost;
};


class actor {
  
  public:

  char* name;
  int hp;
  int totalHP;
  int strength;
  int defense;
  int speed;
  int special;
  byte* bmp;
  int wallet;
  int level;
  equpment weapon;
  equpment inventory[5];

   actor(char* nm, int h, int str, int def, int spd, int spc, byte BMP, equpment Item);
  // pickClass(int type);
   
   printStats();
   getHP(); 
   pickClass(int x);
   damage();
   takeDamage(actor attacker, int x);
   equipt(int inventoryLocation);
   takeSpecial(actor attacker);
   printInv();
   levelUp();

};

//class warrior: public actor {
  //public:
  //equpment weapon;
  
//};

//class tank: public actor {
 // equpment weapon;
  
//};

//class mage: public actor {
  //equpment weapon;
  
//};

#endif actor_h



