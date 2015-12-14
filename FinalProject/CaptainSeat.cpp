//
//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "CaptainSeat.hpp"
#include "Character.hpp"

CaptainSeat::CaptainSeat() : Space() {
    this->hasCoffee = false;
}

void CaptainSeat::lookAround() {
    if (hasCoffee) {
        std::cout << "You're sitting with the Captain. He doesn't look so grumpy any more.\n"
        << "What's that shiny thing poking out of his coat pocket?\n";
    } else {
        std::cout << "You're sitting with the Captain. He looks grumpy.\n";
    }
}

void CaptainSeat::talk() {
    if (hasCoffee) {
        std::cout << "CAPTAIN: Hello there. I'm feeling much better now that I've had my coffee.\n";
        sleep(1);
        std::cout << "So, you're looking for your phone, eh?\n";
        sleep(1);
        std::cout << "I understand there's a secrect cargo area in the back of the plane.\n"
        << "Maybe it's in there.\n";
        sleep(1);
    } else {
        std::cout << "CAPTAIN: *Grumble* Don't talk to me...I haven't had my coffee today...\n";
    }
}

void CaptainSeat::manipulate() {
    if (this->character->objectSearch("Coffee")) {
        std::cout << "CAPTAIN:: Gee! Thanks! I needed that.\n";
        sleep(1);
        std::cout << "So, you lost your phone? Well, it's probably in\n"
        << "the lost and found area all the way in back.\n"
        << "Here's the key\n";
        this->character->setHasKey(true);
    } else {
        std::cout << "CAPTAIN: Huh? I don't want any of your stuff.\n";
    }
}