//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "DrinkCart.hpp"
#include "Character.hpp"

void DrinkCart::lookAround() {
    std::cout << "You're next to the drink cart.\n";
    sleep(1);
    std::cout << "There's a flight attendant nearby to talk to. He looks friendly.\n";
}

void DrinkCart::talk() {
    if (this->character->getHasKey()) {
        std::cout << "FA: Oh, you're back! And I see you have the key to the secret cargo area.\n";
        sleep(1);
        std::cout << "I've been hearing some funny sounds coming from there. Take this fire extinguiser\n"
        << "to use for protection...just in case.\n";
    } else {
        std::cout << "Hi! I heard you lost your phone. That's too bad. I know there's a lost and found\n"
        << "back here somewhere...\n";
    }
}

void DrinkCart::manipulate() {
    std::cout << "FA: Here, take this energy drink. Maybe you can use it while looking for your phone.\n";
    this->character->addObject("Energy Drink");
    sleep(1);
    std::cout << "YOU: Thanks!\n";
}