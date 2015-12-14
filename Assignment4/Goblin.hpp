//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162

#ifndef __Discworld__Goblin__
#define __Discworld__Goblin__

#include "Creature.hpp"

class Goblin : public Creature {
private:
    bool halved;
public:
    Goblin();
    void setHalved(bool); // Used for Achilles attack
    bool getHalved(); // Used for Achilles attack
    void attack(Creature*);
    int defend();
    void takeDamage(int); // Overridden because of Achilles
    bool isGoblin(); // Overridden to return true
};

#endif
