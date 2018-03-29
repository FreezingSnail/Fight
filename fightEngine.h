#ifndef fightEngine_h
#define fightEngine_h
#include "gameEngine.h"
#include "Globals.h"
#include "actor.h"
#include "player.h"

enum moveType {
  attack,
  defend,
  special,
  magic,
  item,
  skip, 
};

class Command
{
public:
    virtual Command() {}
    virtual void execute(actor& actor) = 0;
};


class Attack : public Command
{
public:
    virtual void execute(actor& actor)
  {
    //actor.jump();
  }
};

class InputHandler
{
public:
  Command* handleInput();

  // Methods to bind commands...

private:
  Command* aButton_;
};



void Engagement(playerCharacter& plyr, actor& cpu);
void engage(actor& agressor, actor& target, moveType agresMove, moveType trgtMove);  

#endif // fightEngine_h
