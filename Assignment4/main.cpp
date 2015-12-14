//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162

#include <iostream>
#include <unistd.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include "Combat.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "Creature.hpp"

void creatureSort(std::vector<Creature*>&);

int main() {
    
    srand(time(NULL));
    bool startOver = true;
    bool firstInp = true;
    
    Queue *playerQueue = new Queue();
    Queue *computerQueue = new Queue();
    Stack *loserStack = new Stack();

    while (true) {
        Creature *player;
        Creature *computer;
        Combat combat;
        std::string name;
        int teamSize;
        
        Creature *type = combat.createCharacterOfType(2, "Bob");
        
        if (startOver) {
            startOver = false;
            std::cout << "\n\n-- Welcome to Discworld! --\n"
            << "A fantasy combat game.\n\n";
            
            std::cout << "What would you like to name your team?\n"
            << "Enter your team name: ";
            
            if (firstInp) {
                std::getline(std::cin, name);
                firstInp = false;
            } else {
                std::cin.clear();
                std::cin.ignore(100, '\n');
                std::getline(std::cin, name);
            }
            
            std::cout << "And how many Creatures would you like to employ on your team?\n"
            << "Enter number from 1 to 10: ";
            while (!(std::cin >> teamSize) || (teamSize < 1 || teamSize > 10)) {
                std::cout << "Oops choose a number from 1 to 10.";
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
 
            std::cout << "\nOk " << name << std::endl;
            std::cout << "Now let's choose characters...\n\n";
            sleep(2);
            write(1,"\E[H\E[2J",7); // Clear screen
            std::cout << "There are five types of characters in Discworld: \n\n";
            sleep(1);
            std::cout << "** Goblin ** \nThey are small, not fast and not strong.\n"
            << "Armor: 3\n" << "Attack: 2d6\n" << "Defense: 1d6\n" << "Strength Points: 8\n"
            << "Special: Achilles - roll a 12 and enemy's attack is halved.\n\n";
            sleep(1);
            std::cout << "** Barbarian **\nBig, powerful, with tough skin but very slow.\n"
            << "Armor: 0\n" << "Attack: 2d6\n" << "Defense: 2d6\n" << "Strength Points: 12\n\n";
            sleep(1);
            std::cout << "** Reptile People **\nThink Conan or Hercules from the movies.\n"
            << "Big sword, big muscles, bare torso.\n"
            << "Armor: 7\n" << "Attack: 3d6\n" << "Defense: 1d6\n" << "Strength Points: 18\n\n";
            sleep(1);
            std::cout << "** Blue Men **\nThey are small, fast and tough. Hard to hit and\n"
            << "can take some damage.\n"
            << "Armor: 3\n" << "Attack 2d10\n" << "Defense: 3d6\n" << "Strengh Points: 12\n\n";
            sleep(1);
            std::cout << "** The Shadow **\nA shadowy figure with a strong special attack\n"
            << "Armor: 0\n" << "Attack: 2d10\n" << "Defense: 1d6\n" << "Strength Points: 12\n"
            << "Special: For a given attack there's a 50% chance that The Shadow is somewhere\n"
            << "else and no damage is received\n";
            sleep(1);
            std::cout << "\nTime to choose: \n";
            
            for (int i = 0; i < teamSize; i++) {
                std::cout << "1. Goblin\n2. Barbarian\n3. Reptile People\n4. Blue Men\n5. The Shadow\n";
                int c;
                std::cout << "Enter your choice: ";
                while (!(std::cin >> c) || (c < 1 || c > 5)) {
                    std::cout << "Oops choose a number from the list.";
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                }
                
                std::string playerName;
                std::cout << "Enter this character's name: ";
                std::cin.clear();
                std::cin.ignore(100, '\n');
                std::getline(std::cin, playerName);
                
                player = combat.createCharacterOfType(c, playerName, name);
                playerQueue->add(player);
                
                std::string type;
                switch (c) {
                    case 1:
                        type = "Goblin";
                        break;
                    case 2:
                        type = "Barbarian";
                        break;
                    case 3:
                        type = "Reptile People";
                        break;
                    case 4:
                        type = "Blue Men";
                        break;
                    case 5:
                        type = "The Shadow";
                        break;
                    default:
                        break;
                }
                
                std::cout << "You chose " << type << std::endl;
                sleep(1);
                }
            }
            
        std::cout << "\nTime to choose your computer opponents...\n" << std::endl;
        
        for (int i = 0; i < teamSize; i++) {
            std::cout << "1. Goblin\n2. Barbarian\n3. Reptile People\n4. Blue Men\n5. The Shadow\n";
            std::cout << "Enter your choice: ";
            int o;
            while (!(std::cin >> o) || (o < 1 || o > 5)) {
                std::cout << "Oops choose a number from the list.";
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            
            std::string computerName;
            std::cout << "Enter this character's name: ";
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::getline(std::cin, computerName);
            
            computer = combat.createCharacterOfType(o, computerName, "Computer Team");
            computerQueue->add(computer);
            
            std::string opponent;
            switch (o) {
                case 1:
                    opponent = "Goblin";
                    break;
                case 2:
                    opponent = "Barbarian";
                    break;
                case 3:
                    opponent = "Reptile People";
                    break;
                case 4:
                    opponent = "Blue Men";
                    break;
                case 5:
                    opponent = "The Shadow";
                    break;
                default:
                    break;
            }
            
            std::cout << "Opponent added\n" << std::endl;
            sleep(1);
        }
        
        
        std::cout << "\n\nTime to face off!\n\n";
        sleep(1);
        
        bool fighting = true;
        bool first = true;
        
        while (fighting) {
            combat.combatBetween(playerQueue->getFront(), computerQueue->getFront());
            loserStack->add(combat.getLoser(playerQueue->getFront(), computerQueue->getFront()));
            
            if (playerQueue->getFront()->isAlive()) {
                playerQueue->frontToBack();
            } else {
                playerQueue->removeFront();
            }
            
            if (computerQueue->getFront()->isAlive()) {
                computerQueue->frontToBack();
            } else {
                computerQueue->removeFront();
            }
            
            if (playerQueue->isEmpty() || computerQueue->isEmpty()) {
                fighting = false;
            }
        }
        
        std::string loser = playerQueue->isEmpty() ? name : "Computer Team";
        Queue *winner = playerQueue->isEmpty() ? computerQueue : playerQueue;
        std::cout << "\nThe last character for " << loser << " has been defeated!\n"
        << "The winning team based on points is:\n";
        
        std::cout << winner->getFront()->getTeamName() << "! With " << winner->calculatePoints() << " points.\n";
        
        std::cout << "Individual winners are as follows:\n";
        
        std::vector<Creature *> winners;
        while (!playerQueue->isEmpty()) {
            winners.push_back(playerQueue->getFront());
            playerQueue->removeFront();
        }
        
        while (!computerQueue->isEmpty()) {
            winners.push_back(computerQueue->getFront());
            computerQueue->removeFront();
        }
        
        if (winners.size() < 3) {
            int i = 0;
            std::vector<Creature*> w = loserStack->returnContents();
            creatureSort(w);
            while (winners.size() < 3) {
                winners.push_back(w[i]);
                i++;
            }
        }
        
        creatureSort(winners);
        
        for (int i = 0; i < 3; i++) {
            std::cout << i+1 << ". " << winners[i]->getName() << " - "
            << winners[i]->getTournamentPoints() << " points" << std::endl;
        }
        
        
        std::cout << "\nDefeated characters in order of their loss are:\n\n";
        loserStack->printStack();
        
        std::cout << "\n\nGame Over.";
        break;
    }
}

void creatureSort(std::vector<Creature*> &v) {
    int i, j, flag = 1;
    Creature *temp;
    int len = v.size();
    for (i = 0; (i <= len) && flag; i++) {
        flag = 0;
        for (j = 0; j < (len - 1); j++) {
            if (v[j+1]->getTournamentPoints() > v[j]->getTournamentPoints()) {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                flag = 1;
            }
        }
    }
    return;
}