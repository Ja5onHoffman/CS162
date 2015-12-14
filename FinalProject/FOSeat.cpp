//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "FOSeat.hpp"
#include "Character.hpp"

void FOSeat::talk() {
    std::cout << "FO: Hi there. I understand you lost your phone? Well, it might be in the lost and "
    << "found.\n";
    sleep(1);
    std::cout << "Do you have the key?\n";
    sleep(1);
    std::cout << "YOU: No...\n"
    << "FO: Well, if you can cheer up the captain, maybe he'll give it to you.\n"
    << "He can't function without his coffee. Considering he's flying the plane,\n"
    << "maybe you should give him some.";
}

void FOSeat::lookAround() {
    std::cout << "You're sitting with the First Officer. You should talk to him.\n";
}

void FOSeat::manipulate() {
    std::cout << "Here's some coffee for the captain. Go see if he wants it.\n";
    this->character->addObject("Coffee");
    sleep(1);
    std::cout << "YOU: Thanks! Bye.\n";
}