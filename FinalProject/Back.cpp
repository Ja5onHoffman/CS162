//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "Back.hpp"

void Back::lookAround() {
    std::cout << "You're in the back of the airplane. To your left is the lav,\n"
    << "to your right is a flight attendant next to the drink cart, and economy\n"
    << "class is in front of you.\n";
    sleep(1);
    std::cout << "Behind you is a mysterious looking door. It seems to be locked...\n";
}

void Back::talk() {
    std::cout << "You might be able to talk to that FA over there..\n";
}