//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "Character.hpp"
#include "Space.hpp"

Character::Character() {
    this->hasCKey = false;
    this->hasKey = false;
}

void Character::setName(std::string n) {
    this->name = n;
}

void Character::setHasKey(bool b) {
    this->hasKey = b;
}

void Character::setHasCKey(bool b) {
    this->hasCKey = b;
}

void Character::setCurrentSpace(Space *c) {
    this->currentSpace = c;
}

Space* Character::getCurrentSpace() {
    return this->currentSpace;
}

bool Character::getHasKey() {
    return this->hasKey;
}

bool Character::getHasCKey() {
    return this->hasCKey;
}

// Movement functions check for NULL pointers, then move or display a message

void Character::moveFwd() {
    if (currentSpace->getFwd() != NULL) {
        // If space requires key (cockpit) 
        if (!currentSpace->getFwd()->getRequiresKey()) {
            std::cout << "\nMoving forward...";
            sleep(1);
            this->currentSpace = currentSpace->getFwd();
            std::cout << "You're now " << this->currentSpace->getSpaceName();
        } else {
            if (currentSpace->getFwd()->getSpaceName() == "in the cockpit") {
                if (this->getHasCKey()) {
                    this->currentSpace = currentSpace->getFwd();
                    std::cout << "\nMoving forward...\n"
                    << "** Entering the cockpit **\n";
                } else {
                    std::cout << "\nThe cockpit seems to be locked.\n";
                }
            }
        }
    } else {
        std::cout << "\nThere's no way forward from here.\n";
    }
}

void Character::moveBack() {
    if (currentSpace->getBack() != NULL) {
        if (!currentSpace->getBack()->getRequiresKey()) {
            std::cout << "\nMoving backward...";
            sleep(1);
            this->currentSpace = currentSpace->getBack();
            std::cout << "You're now " << this->currentSpace->getSpaceName();
        } else {
            if (currentSpace->getBack()->getSpaceName() == "in the secret cargo area") {
                if (this->getHasKey()) {
                    this->currentSpace = currentSpace->getBack();
                    std::cout << "\nMoving backward...\n"
                    << "** Entering the secret cargo area **\n";
                } else {
                    std::cout << "\nThis door seems to be locked.\n";
                }
            } else if (currentSpace->getBack()->getSpaceName() == "in the cockpit") {
                std::cout << "\nMoving backward...";
                sleep(1);
                this->currentSpace = currentSpace->getBack();
                std::cout << "You're now " << this->currentSpace->getSpaceName();
            }
        }
    } else {
        std::cout << "\nThere's no way backward from here.\n";
    }
}

void Character::moveLeft() {
    if (currentSpace->getLeft() != NULL) {
        std::cout << "\nMoving left...";
        sleep(1);
        this->currentSpace = currentSpace->getLeft();
        std::cout << "You're now " << this->currentSpace->getSpaceName();
    } else {
        std::cout << "\nYou can't go that way.\n";
    }
}

void Character::moveRight() {
    if (currentSpace->getRight() != NULL) {
        std::cout << "\nMoving right...";
        sleep(1);
        this->currentSpace = currentSpace->getRight();
        std::cout << "You're now " << this->currentSpace->getSpaceName();
    } else {
        std::cout << "\nYou can't go that way.\n";
    }
}

std::string Character::getName() {
    return this->name;
}

void Character::addObject(std::string o) {
    this->objects.push_back(o);
    std::cout << "\n\n** " << o << " acquired **\n";
}

bool Character::objectSearch(std::string s) {
    for (int i = 0; i < this->objects.size(); i++) {
        if (objects[i] == s) {
            return true;
        }
    }
    
    return false;
}