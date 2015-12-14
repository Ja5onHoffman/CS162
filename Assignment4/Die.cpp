//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162

#include "Die.hpp"
#include <stdlib.h>
#include <time.h>

Die::Die() {
    setSides(0);
}

Die::Die(int s) {
    this->sides = s;
}

void Die::setSides(int i) {
    sides = i;
}

int Die::roll() {
//    srand(time(NULL));
    int roll;
    // Roll uses random number between 0 and 6 (sides)
    roll = rand() % sides + 1;
    return roll;
}