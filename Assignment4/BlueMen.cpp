//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162

#include "BlueMen.hpp"

BlueMen::BlueMen() : Creature(3, // armor
                              12, // strengthPoints
                              true, // alive
                              "",
                              ""
                              ) {
    this->attackDie = new Die();
    this->defenseDie = new Die();
    this->attackDie->setSides(10);
    this->defenseDie->setSides(6);
    this->defeatPoints = 7;
}

int BlueMen::defend() {
    int d = this->defenseDie->roll();
    d += this->defenseDie->roll();
    d += this->defenseDie->roll();
    return d;
}