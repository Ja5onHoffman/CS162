//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "SecretCargo.hpp"

SecretCargo::SecretCargo() : Space() {
    this->requiresKey = true;
}

void SecretCargo::lookAround() {
    std::cout << "You've entered a dark area in the back of the plane.\n"
    << "Surrounding you are a plethora of tablets, e-readers and phones.";
    sleep(1);
    std::cout<< "Is that your phone in the corner?";
}

// The game ends with a riddle that must be solved to retreive your phone

void SecretCargo::talk() {
    std::cout << "Hello. I am the keeper of the lost and found.\n"
    << "It seems you've gone to great lengths to get here.";
    sleep(1);
    std::cout << "To retreive your phone, you must first solve a riddle.\n\n"
    << "Riddle: Poor people have it. Rich people need it. If you eat it you die.\n";
    std::string answer;
    std::cout << "Enter your answer: ";
    std::cin.clear();
    while (!std::getline(std::cin, answer)) {
        std::cout << "Enter your answer: ";
    }
    
    bool wrong = true;
    while (wrong) {
        if (answer == "Nothing") {
            wrong = false;
            std::cout << "That is correct. You have earned your phone back.\n"
            << "Thank you for flying with us.\n\n";
            sleep(1);
            std::cout << "**********************************\n**********************************\n"
            << "YOU WON! Thanks for playing.";
        } else {
            std::cout << "That is incorrect. Try again\n"
            << "Enter your answer: ";
            std::cin.clear();
            std::getline(std::cin, answer);
        }
    }
}

void SecretCargo::manipulate() {
    std::cout << "Nothing to manipulate. Try talking.\n";
}