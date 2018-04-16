#ifndef fightEngine_h
#define fightEngine_h
#include "gameEngine.h"
#include "Globals.h"
#include "actor.h"
#include "player.h"
#include "attacks.h"





void Engagement(playerCharacter& plyr, actor& cpu);
void engage(actor& agressor, actor& target, moveType agresMove, moveType trgtMov, int attackmovepower);  
void getPlayerMove(playerCharacter & plyr);
void getCPUMove();
void selectAttack(playerCharacter & plyr);
void selectMagic();


#endif // fightEngine_h
