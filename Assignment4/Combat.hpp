//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162

#ifndef __Discworld__Combat__
#define __Discworld__Combat__

#include "Creature.hpp"
#include <string>

class Combat {
public:
    void combatBetween(Creature*, Creature*);
    Creature* getWinner(Creature*, Creature*);
    Creature* getLoser(Creature*, Creature*);
    Creature* createCharacterOfType(int, std::string, std::string tm = "");
};

#endif