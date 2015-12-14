//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "ArnoldS.hpp"
#include "Character.hpp"

void ArnoldS::lookAround() {
    std::cout << "You're sitting next to Arnold Schwarzenegger. He looks big.\n";
}

void ArnoldS::talk() {
    std::cout << "ARNOLD: The Governator is sorry that you lost your phone.\n";
    sleep(1);
    std::cout << "That flight attendant up front wants my autograph, but I forgot her name...\n";
}

void ArnoldS::manipulate() {
    if (this->character->objectSearch("Sally")) {
        std::cout << "Outstanding. Here's an autograph for Sally. Can you give it to her?\n";
        this->character->addObject("Autograph");
    } else {
        std::cout << "If only I knew the flight attendant's names, I could give her that autograph.\n"
        << "I wonder if anyone nearby knows it...\n";
    }
}