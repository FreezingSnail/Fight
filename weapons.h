#ifndef  weapons_h
#define  weapons_h

struct weapon {
  uint16_t atkMod;
  uint16_t defMod;
  uint16_t spcMod;
  const char* name;
  uint16_t cost;
};

enum weaponId : uint8_t {
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
  club,
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
//const char PROGMEM WpnNmclub[] = "club";



const weapon weaponArray[] PROGMEM = {
  { 0, 0, 0, WpnEmpty, 0, },
  { 1, 0, 0, WpnNmSword, 0 },
  { 0, 1, 0, WpnNmSheild, 0},
  { 0, 0, 1, WpnNmStaff, 0 }, 
  {5, 2, 0, WpnNmKleaver, 10},
  {2, 5, 0, WpnNmBroadSheild, 20},
  {0, 2, 5, WpnNmWand, 30},
  {7, 5, 3, WpnNmKatana, 40},
  {5, 7, 3, WpnNmIronSheild, 50},
  {3, 5, 7, WpnNmMagnusRod, 60},
 // {4, 2, 0, WpnNmclub, 10},
    };

constexpr inline const __FlashStringHelper * FlashString(const char * flashString)
{
  return reinterpret_cast<const __FlashStringHelper*>(flashString);
}

#endif weapons_h
