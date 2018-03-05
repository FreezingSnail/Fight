#ifndef fightEngine_h
#define fightEngine_h
#include "actor.h"
#include "Globals.h"

void Engagement(actor& plyr, actor& cpu);
void engage(actor& agressor, actor& target, moveType agresMove, moveType trgtMove);   

#endif fightEngine_h
