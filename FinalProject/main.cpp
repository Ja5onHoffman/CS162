//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include <iostream>
#include <unistd.h>
#include "PlaneWorld.hpp"
#include "Character.hpp"

void gameLoop(Character*);

int main() {
    
    // Planeworld is instantiated and character pointer set to PlaneWorld's Character object
    PlaneWorld *planeWorld = new PlaneWorld();
    Character *character = planeWorld->getCharacter();
    
    while (true) {
        std::cout << "** Welcome to OSU Air! ** \n\n"
        << "This is an adventure game in which your character explores\n"
        << "an airplane looking for their lost iPhone. Acquire objects along\n"
        << "the way to gain clues and access to different areas.\n";
        
        std::cout << "What would you like to name your character?\n"
        << "Enter character name: ";
        std::string name;
        std::cin.clear();
        std::getline(std::cin, name);
        character->setName(name);
        std::cout << "Ok, " << character->getName() << ". Let's go!\n\n";
        sleep(1);
        std::cout << "Instructions: To explore the game world, your character can move\n"
        << "forward, back, left or right. The character is always facing forward, toward the\n"
        << "front of the plane.\n\n";
        sleep(1);
        std::cout << "The character can interact with each new location with three actions:\n"
        << "- look around\n- talk\n- manipulate\n\n";
        sleep(1);
        std::cout << "Some spaces have other characters to talk to or objects to manipulate, while in\n"
        << "others you can only look around. 'manipulate' is also used acquire objects from\n"
        << "other characters.\n\n";
        sleep(1);
        std::cout << "Moving: To move in the game, enter '4', then the direction you want to move.\n"
        << "For example: 'f' means \"move forward\", 'b means \"move backward\".\n";
        sleep(1);
        std::cout << "EXIT: To exit the game, enter 5 as your choice at any time.";
        int o;
        std::cout << "\nWhen you're ready, press '1' and Enter to continue.";
        while (!(std::cin >> o) || (o < 1 || 0 > 1)) {
            std::cin.clear();
            std::cout << "Press '1' to continue.";
        }
        
        std::cout << "Transporting " << name << " into the game...\n\n";
        std::cout << "***************************************\n***************************************\n\n";
        std::cout << "You're somewhere on a plane headed to Portland.\n\n";
        
        gameLoop(character);
        
        std::cout << "\nSee ya!\n";
        break;
    }
}

void gameLoop(Character *c) {
    bool loop = true;
    while (loop) {
        sleep(1);
        std::cout << "\n\nWhat would you like to do?\n";
        std::cout << "1. look around\n2. talk\n3. manipulate\n4. move\n\n"
        << "Enter choice: ";
        std::cin.clear();
        int m;
        while (!(std::cin >> m) || (m < 1 || m > 5)) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "\nEnter choice: ";
        }
        
        switch (m) {
            case 1:
                c->getCurrentSpace()->lookAround();
                break;
            case 2:
                c->getCurrentSpace()->talk();
                break;
            case 3:
                c->getCurrentSpace()->manipulate();
                break;
            case 4:
                char d;
                std::cout << "\nWhich direction?\n";
                do {
                    std::cout << "Direction - (f)orward, (b)ack, (l)eft, (r)ight: ";
                    std::cin.ignore();
                    std::cin >> d;
                } while (d != 'f' && d != 'b' && d != 'l' && d != 'r');
                
                switch (d) {
                    case 'f':
                        c->moveFwd();
                        break;
                    case 'b':
                        c->moveBack();
                        break;
                    case 'l':
                        c->moveLeft();
                        break;
                    case 'r':
                        c->moveRight();
                        break;
                    default:
                        break;
                }
                break;
            case 5:
                loop = false;
                break;
            default:
                break;
        }
    }
}
