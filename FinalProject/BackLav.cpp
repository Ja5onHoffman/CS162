//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "BackLav.hpp"

void BackLav::lookAround() {
    std::cout << "You're in the back lav of an airplane feeling sad about losing\n"
    << "your new iPhone. It must be on this plane somewhere!\n";
    sleep(1);
    std::cout << "There doesn't seem to be anything useful in\n"
    << "the bathroom (this is your starting point). The exit is to the right.\n";
}

void BackLav::talk() {
    std::cout << "Why not exit the lav and look around?\n";
}