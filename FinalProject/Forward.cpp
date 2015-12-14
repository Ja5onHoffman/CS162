//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "Forward.hpp"

void Forward::lookAround() {
    std::cout << "You're in the forward flight attendant area.\n";
    sleep(1);
    std::cout << "To your left is the front lav, to your right is the front galley,\n"
    << "where one of the attendants is standing.\n";
}

void Forward::talk() {
    std::cout << "Nobody to talk to here, why not go left or right?\n";
}