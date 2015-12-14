//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162

#include "Barbarian.hpp"

Barbarian::Barbarian() : Creature(
                                  0, // armor
                                  12, // strengthPoints
                                  true, // alive
                                  "",
                                  ""
                                  ) {
    this->attackDie = new Die(); // Die objects have to be instntiated here
    this->defenseDie = new Die();
    this->attackDie->setSides(6); // Sides set in constructor for each class because they differ
    this->defenseDie->setSides(6);
    this->defeatPoints = 5;
}



// Two die rolls
int Barbarian::defend() {
    int d = this->defenseDie->roll();
    d += this->defenseDie->roll();
    return d;
}