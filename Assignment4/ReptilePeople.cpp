//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162

#include "ReptilePeople.hpp"

ReptilePeople::ReptilePeople() : Creature(7, // armor
                                          18, // strengthPoints
                                          true, // alive
                                          "",
                                          ""
                                          ) {
    this->attackDie = new Die();
    this->defenseDie = new Die();
    this->attackDie->setSides(6);
    this->defenseDie->setSides(6);
    this->defeatPoints = 10;
}

// Three die rolls
void ReptilePeople::attack(Creature *c) {
    int a = this->attackDie->roll();
    a += this->attackDie->roll();
    a+= this->attackDie->roll();

    c->takeDamage(a);
}

int ReptilePeople::defend() {
    std::cout << this->name << " is defending...\n";
    return this->defenseDie->roll();
}