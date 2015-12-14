//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "FrontGalley.hpp"
#include "Character.hpp"

void FrontGalley::lookAround() {
    std::cout << "You're in the front galley. There's a flight attendant here to talk to.\n";
}

void FrontGalley::talk() {
    std::cout << "FA: Hi there! So, you lost your phone?\n";
    sleep(1);
    std::cout << "They say the Captain has a key to the rear storage area...\n"
    << "Maybe it's in there.\n";
    sleep(1);
    std::cout << "You need to know the secret knock to get into the cockpit.\n"
    << "Do you have anything for me? *wink* *wink*\n";
}

void FrontGalley::manipulate() {
    if (this->character->objectSearch("Autograph")) {
        std::cout << "FA: Oh, yay! I was hoping I could get his autograph. My friends will be so jealous.\n";
        sleep(1);
        std::cout << "Since you've been such a big help, I'll help you get into the cockpit.\n";
        sleep(1);
        std::cout << "I don't remember the knock, but it's written behind a secret panel in the\n"
        << "front lav. Here's a key to open it...";
        this->character->addObject("Lav Key");
    }
}