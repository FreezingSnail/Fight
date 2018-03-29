#ifndef  weapons_h
#define  weapons_h

struct weapon {
  uint16_t atkMod;
  uint16_t defMod;
  uint16_t spcMod;
  const char* name;
  uint16_t cost;
};

enum weaponId : uint16_t {
  empty,
  sword, 
  sheild,
  staff,
  kleaver,
  broadSheild,
  wand,
  katana,
  ironShield,
  magnusRod,
  };
  
const char PROGMEM WpnEmpty[] = "Empty";
const char PROGMEM WpnNmSword[] = "Sword";
const char PROGMEM WpnNmSheild[] = "Sheild";
const char PROGMEM WpnNmStaff[] = "Staff";
const char PROGMEM WpnNmKleaver[] = "Kleaver";
const char PROGMEM WpnNmKatana[]  = "Katana";
const char PROGMEM WpnNmMagnusRod[] = "Magnus Rod";
const char PROGMEM WpnNmBroadSheild[] = "Broad Sheild";
const char PROGMEM WpnNmWand[] = "Wand";
const char PROGMEM WpnNmIronSheild[] = "IronSheild";

/*
const weapon PROGMEM kleaver = {5, 2, 0, WpnNmKleaver, 10};
const weapon PROGMEM broadSheild = {2, 5, 0, WpnNmBroadSheild, 10};
const weapon PROGMEM wand = {0, 2, 5, WpnNmWand, 10};
const weapon PROGMEM katana = {7, 5, 3, WpnNmKatana, 20};
const weapon PROGMEM ironSheild = {5, 7, 3, WpnNmIronSheild, 20};
const weapon PROGMEM magnusRod = {3, 5, 7, WpnNmMagnusRod, 20};
const weapon PROGMEM sword = { 1, 0, 0, WpnNmSword, 10 };
const weapon PROGMEM sheild = { 0, 1, 0, WpnNmSheild, 0};
const weapon PROGMEM staff = { 0, 0, 1, WpnNmStaff, 0 };
*/
const static weapon weaponArray[] PROGMEM = {
  { 0, 0, 0, WpnEmpty, 0, },
  { 1, 0, 0, WpnNmSword, 0 },
  { 0, 1, 0, WpnNmSheild, 0},
  { 0, 0, 1, WpnNmStaff, 0 }, 
  {5, 2, 0, WpnNmKleaver, 10},
  {2, 5, 0, WpnNmBroadSheild, 20},
  {0, 2, 5, WpnNmWand, 30},
  {7, 5, 3, WpnNmKatana, 40},
  {5, 7, 3, WpnNmIronSheild, 50},
  {3, 5, 7, WpnNmMagnusRod, 60}
    };

constexpr inline const __FlashStringHelper * FlashString(const char * flashString)
{
  return reinterpret_cast<const __FlashStringHelper*>(flashString);
}

#endif weapons_h
