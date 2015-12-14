//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162

#ifndef __Discworld__Creature__
#define __Discworld__Creature__

#include "Die.hpp"
#include <string>
#include <iostream>

class Creature {

protected:
    Die *attackDie; // Separate die for attack and defense
    Die *defenseDie;
    std::string name;
    std::string teamName;
    int armor;
    int defeatPoints;
    int strengthPoints;
    int tournamentPoints; // Added for Assignment 4
    bool alive;
public:
    Creature();
    Creature(int, int, bool, std::string, std::string);
    virtual void attack(Creature*);
    virtual int defend() = 0; // Pure virtual function
    virtual void takeDamage(int);
    virtual bool isGoblin();
    void incrementPoints(int);
    int getDamage();
    void setName(std::string);
    void setTeamName(std::string);
    std::string getTeamName();
    std::string getName();
    bool isAlive();
    int getTournamentPoints();
    int getDefeatPoints();
};

#endif