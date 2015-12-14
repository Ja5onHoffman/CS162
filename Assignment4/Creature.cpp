//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162

#include "Creature.hpp"

// Default constructor sets everything to a placeholder
Creature::Creature() {
    this->attackDie = new Die();
    this->defenseDie = new Die(); 
    this->attackDie->setSides(0);
    this->defenseDie->setSides(0);
    this->armor = 0;
    this->strengthPoints = 0;
    this->tournamentPoints = 0;
    this->alive = false;
    this->name = "";
}

// Creature constructor used for all classes derived from Creature
Creature::Creature(int a, int sP, bool al, std::string n, std::string tm) {
    this->armor = a;
    this->strengthPoints = sP;
    this->alive = true;
    this->name = n;
    this->teamName = tm;
}

// Name setter
void Creature::setName(std::string n) {
    this->name = n;
}

void Creature::setTeamName(std::string tm) {
    this->teamName = tm;
}

std::string Creature::getTeamName() {
    return this->teamName;
}

std::string Creature::getName() {
    return this->name;
}

// Two rolls for all but Reptile people
void Creature::attack(Creature *c) {
    int a = this->attackDie->roll();
    a += this->attackDie->roll();
    
    // After attack roll, attacked creature's takeDamage()
    // function is called
    c->takeDamage(a);
}

int Creature::getDamage() {
    return this->strengthPoints;
}

int Creature::getDefeatPoints() {
    return this->defeatPoints;
}

void Creature::takeDamage(int a) {
    int d = this->defend() + this->armor;
    a -= d;
    if (a < 0) { // If a - d < 0, simply set a to 0.
        a = 0;
    }
    
    std::cout << this->name << " took " << a << " damage.\n";
    this->strengthPoints -= a; // Subtract attack from strengthPoints
    
    if (this->strengthPoints <= 0) {
        this->strengthPoints = 0;
        this->alive = false; // defeated
    }
}

int Creature::getTournamentPoints() {
    return this->tournamentPoints;
}

void Creature::incrementPoints(int dp) {
    this->tournamentPoints += dp;
}

bool Creature::isGoblin() {
    return false;
}

bool Creature::isAlive() {
    return this->alive;
}