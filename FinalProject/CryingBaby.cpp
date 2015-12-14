//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "CryingBaby.hpp"
#include "Character.hpp"

CryingBaby::CryingBaby() {
    this->crying = true;
}

void CryingBaby::setCrying(bool b) {
    this->crying = b;
}

bool CryingBaby::getCrying() {
    return this->crying;
}

void CryingBaby::lookAround() {
    std::string baby;
    if (this->getCrying()) {
        baby = "crying baby";
    } else {
        baby = "happy baby";
    }
    std::cout << "You're sitting next to a " << baby << " and her sister.\n";
}

void CryingBaby::talk() {
    std::cout << "\nSISTER: OMG! I can't seem to get him to stop crying!\n";
    sleep(1);
    std::cout << "He LOVES candy. *LOL*\n";
    std::cout << "Can you help me?\n";
}

void CryingBaby::manipulate() {
    if (this->character->objectSearch("Candy")) {
        this->setCrying(false);
        std::cout << "SISTER: Yay!! Thanks for the candy. I know he'll stop crying now.\n";
        sleep(1);
        std::cout << "(baby stops crying)";
        sleep(1);
        std::cout << "SISTER: LOOK!!..Someone just posed Selena Gomez's PHONE NUMBER\n"
        << "on Twitter!\n";
        sleep(1);
        std::cout << "I heard Justin Bieber is sitting up front. I wonder if he knows...\n";
        this->character->addObject("Selena's number");
    } else {
        std::cout << "SISTER: Yep..he's still crying. If only I had some candy...\n";
    }
}