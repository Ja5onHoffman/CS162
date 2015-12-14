//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162

#include "TheShadow.hpp"
#include <stdlib.h>
#include <iostream>

TheShadow::TheShadow() : Creature(0, // armor
                                  12, // strengthPoints
                                  true, // alive
                                  "",
                                  ""
                                  ) {
    this->attackDie = new Die();
    this->defenseDie = new Die();
    this->attackDie->setSides(10);
    this->defenseDie->setSides(6);
    this->defeatPoints = 9;
}



int TheShadow::defend() {
    srand(time(NULL));
    bool sp = rand() % 2; // 50/50 chance of 0 or 1
    
    if (sp) { // If 1 no damage
        std::cout << "The Shadow was hiding. No damage!\n";
        return 1000; // more than any attack
    }
    
    // Else normal defense roll
    return this->defenseDie->roll();
}