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

;

struct spellType{
  const char* name;
  uint8_t strength;
  uint8_t mpCost;
  element type;

};



const char PROGMEM splNmFire[] = "Fire";
const char PROGMEM splNmWater[] = "Water";
const char PROGMEM splNmCure[] = "Cure";
const char PROGMEM atkNmSwipe[] = "Swipe";
const char PROGMEM atkNmBash[] = "Bash";

enum spellNames : uint8_t {
  Fire,
  Water,
  Cure,
  Swipe,
  Bash,
};


const spellType PROGMEM spellIndex[] = {
  {splNmFire, 5, 3, fire},
  {splNmWater, 5, 3, water},
  {splNmCure, 5, 5, none},
  {atkNmSwipe, 10, 0, none},
  {atkNmBash, 5, 0, none},
};



#endif
