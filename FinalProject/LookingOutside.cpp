//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "LookingOutside.hpp"
#include <unistd.h>

void LookingOutside::lookAround() {
    std::cout << "\nWhat a beautiful view.\n";
    sleep(1);
    std::cout << "There doesn't seem to be anything here though.\n";
}

void LookingOutside::talk() {
    std::cout << "\nNobody up here. Why not go back and talk to the captain and first officer?\n";
}