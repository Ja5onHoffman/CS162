//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162

#ifndef __Discworld__ReptilePeople__
#define __Discworld__ReptilePeople__

#include "Creature.hpp"

class ReptilePeople : public Creature {

public:
    ReptilePeople();
    void attack(Creature*); // Overridden for 3 attack rolls
    int defend();
};

#endif
