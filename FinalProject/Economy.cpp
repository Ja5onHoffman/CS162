//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "Economy.hpp"

Economy::Economy(CryingBaby *b) : Space() {
    this->baby = b;
}

void Economy::lookAround() {
    std::string baby;
    if (this->baby->getCrying()) {
        baby = "crying baby";
    } else {
        baby = "happy baby";
    }
    std::cout << "You're in economy class. To you right is a drooling sleeper,\n"
    << "to your left is a " << baby << ".\n";
}

void Economy::talk() {
    std::cout << "See if you can talk to anyone next to you...\n";
}