//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "DroolingSleeper.hpp"
#include "Character.hpp"

void DroolingSleeper::lookAround() {
    std::cout << "You're sitting next to a drooling sleeper.\n"
    << "I wonder if you could wake him?\n";
}

void DroolingSleeper::talk() {
    if (this->awake) {
        std::cout << "SLEEPER: Gee! Thanks for waking me up. Good luck finding your phone!\n";
    } else {
        std::cout << "ZZZZZZ...sooo tired...ZZZZ...need to wake up...\n";
    }
}

void DroolingSleeper::manipulate() {
    if (this->character->objectSearch("Energy Drink")) {
        std::cout << "** You gave the sleeper an energy drink **\n";
        sleep(1);
        std::cout << "SLEEPER: Boy I needed that! Thanks for the energy drink.\n";
        sleep(1);
        std::cout << "Here's some candy. My doctor says I can't have sugar.\n";
        this->character->addObject("Candy");
        
    } else {
        std::cout << "SLEEPER: ZZZZ...need..energy drink...ZZZZ\n";
    }
}

void DroolingSleeper::setAwake(bool b) {
    this->awake = b;
}