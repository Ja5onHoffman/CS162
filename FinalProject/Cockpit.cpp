//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "Cockpit.hpp"
#include <unistd.h>

Cockpit::Cockpit() : Space() {
    this->requiresKey = true;
}

void Cockpit::lookAround() {
    std::cout << "\nYou're in the cockpit of the airplane!\n";
    sleep(1);
    std::cout << "The captain is on your left and the first officer is on the right.\n"
    << "In front of you there's room to look out the windshield.\n";
}

void Cockpit::talk() {
    std::cout << "\nYOU: Hi! Thanks for letting me up front.";
    sleep(1);
    std::cout << "\nCAPTAIN: Woah...how'd you get up here???";
    sleep(1);
    std::cout << "\nFO: Well, nice to have a visitor I guess...";
    sleep(1);
    std::cout << "\nCAPTAIN: I haven't had my coffee today. Grrr...";
    sleep(1);
    std::cout << "\nFO: Watch out for him, he's cranky right now. Come right and talk to me.";
}