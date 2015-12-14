//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162
#ifndef __Discworld__BlueMen__
#define __Discworld__BlueMen__

#include "Creature.hpp"

class BlueMen : public Creature {

public:
    BlueMen();
    int defend(); // Overridden for three defense rolls
};

#endif