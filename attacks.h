#ifndef attacks_h
#define attacks_h

enum moveType {
  attack,
  defend,
  special,
  magic,
  item,
  skip, 
};

enum element : uint8_t {
  none,
  fire,
  water,
};

struct attackType{
  const char* name;
  uint8_t strength;
  element type;
  
};

struct spellType{
  const char* name;
  uint8_t strength;
  uint8_t mpCost;
  element type;

};


enum attackNames{
  Swipe,
  Bash,
};

const char PROGMEM atkNmSwipe[] = "Swipe";
const char PROGMEM atkNmBash[] = "Bash";

enum spellNames {
  Fire,
  Water,
  Cure,
};

const char PROGMEM splNmFire = "Fire";
const char PROGMEM splNmWater = "Water";
const char PROGMEM splNmCure = "Cure";

const spellType PROGMEM spellIndex[] = {
  {splNmFire, 5, 3, fire},
  {splNmWater, 5, 3, water},
  {splNmCure, 5, 5, none},
};

const attackType PROGMEM attackIndex[] = {
  {atkNmSwipe, 10, none},
  {atkNmSwipe, 5, none},
};

#endif
