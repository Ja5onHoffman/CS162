//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162

#include "Goblin.hpp"

Goblin::Goblin() : Creature(
                            3, // armor
                            8, // strengthPoints
                            true, // alive
                            "",
                            ""
                            ) {
    this->attackDie = new Die();
    this->defenseDie = new Die();
    this->attackDie->setSides(6);
    this->defenseDie->setSides(6);
    this->halved = false;
    this->defeatPoints = 4;
}

void Goblin::attack(Creature* c) {
    int a = this->attackDie->roll();
    a += this->attackDie->roll();
    
    // If Goblin rolls a 12 and opponent is not a Goblin
    // set halved to true
    if (a == 12 && !c->isGoblin()) {
        std::cout << this->getName() <<" cut the Achilles of " << c->getName()
        <<". Next attack half damage.";
        this->setHalved(true);
    }
    
    c->takeDamage(a);
}

int Goblin::defend() {
    std::cout << this->name << " is defending...\n";
    return this->defenseDie->roll();
}

void Goblin::takeDamage(int a) {

    int d = this->defend() + this->armor;
    bool h = this->getHalved();
    
    // If halved == true, opponents attack value is halved
    if (!h) {
        a -= d;
    } else {
        a -= d/2;
    }
   
    a < 0 ? a = 1 : a;
    
    std::cout << this->name << " took " << a << " damage.\n";
    this->strengthPoints -= a;
    
    if (this->strengthPoints <= 0) {
        this->strengthPoints = 0;
        this->alive = false; // defeated
    }
}

void Goblin::setHalved(bool h) {
    this->halved = h;
}

bool Goblin::getHalved() {
    return this->halved;
}

bool Goblin::isGoblin() {
    return true;
}