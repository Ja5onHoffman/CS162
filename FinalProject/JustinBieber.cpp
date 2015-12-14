//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "JustinBieber.hpp"
#include "Character.hpp"

JustinBieber::JustinBieber() {
    this->sad = true;
}

void JustinBieber::lookAround() {
    std::cout << "You're sitting next to Justin Bieber.\n"
    << "He looks sad.\n";
}

void JustinBieber::talk() {
    if (this->sad) {
        std::cout << "BIEBS: YO! I heard you lost your phone. That's whack!\n"
        << "I'm sad too. I lost Selena's phone number, and now I can't call her.\n";
        sleep(1);
        std::cout << ":'(\n";
    } else {
        std::cout << "BIEBS: Thanks for that number yo! Good luck finding your phone\n";
    }

}

void JustinBieber::manipulate() {
    if (this->character->objectSearch("Selena's number")) {
        this->sad = false;
        std::cout << "Sweet! Now I can call Selena when we land!\n"
        << "Thanks!\n";
        sleep(1);
        std::cout << "By the way...the flight attendant up front, her name is Sally in case you\n"
        << "need anything from her.";
        this->character->addObject("Sally");
    } else {
        std::cout << "Do you have anything for me? No? Whatever...\n";
    }
}