//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "FrontLav.hpp"
#include "Character.hpp"

void FrontLav::lookAround() {
    std::cout << "You're in a smelly airplane lav.\n";
    sleep(1);
    std::cout << "There's a discolored panel next to the toilet.\n"
    << "I wonder if there's anything in there?\n";
}

void FrontLav::manipulate() {
    if (this->character->objectSearch("Lav Key")) {
        std::cout << "You've opened the panel to reveal instructions for the\n"
        << "secret knock. Now you can enter the cockpit!";
        this->character->setHasCKey(true);
    } else {
        std::cout << "Hmm...it doesn't seem to open, but there's a small key hole\n"
        << "on the front. Maybe you need a key?\n";
    }
}

void FrontLav::talk() {
    std::cout << "Nobody to talk to, but you might be able to do something else here...\n";
}