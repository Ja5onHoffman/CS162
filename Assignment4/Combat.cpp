//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162

#include "Combat.hpp"
#include <iostream>
#include <unistd.h>
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Goblin.hpp"
#include "ReptilePeople.hpp"
#include "BlueMen.hpp"
#include "TheShadow.hpp"

void Combat::combatBetween(Creature *player, Creature *computer) {

    while (player->isAlive() && computer->isAlive()) {
        std::cout << player->getName() << " attacks!\n";
        player->attack(computer);
//        sleep(2);
        std::cout << computer->getName() << " attacks!\n";
        computer->attack(player);
//        sleep(2);
        
        std::cout << player->getName() << "'s remaining strength points are: " << player->getDamage() << std::endl
        << "Computer's remaining strength points are: " << computer->getDamage() << std::endl;
    }
    
    if (!player->isAlive() || !computer->isAlive()) {
        Creature *w = this->getWinner(player, computer);
        std::cout << "\n\n" << w->getName() << " wins and lives to fight again!\n"
        << w->getName() << " 's strength is restored'.\n";
        sleep(2);
    }

}

Creature* Combat::getWinner(Creature *player, Creature *computer) {
    Creature *winner;
    if (!computer->isAlive()) {
        winner = player;
    } else if (!player->isAlive()) {
        winner = computer;
    }
    
    Creature *loser = winner == player ? computer : player;
    
    winner->incrementPoints(loser->getDefeatPoints());
    return winner;
}

Creature* Combat::getLoser(Creature *player, Creature* computer) {
    Creature *l = player->isAlive() ? computer : player;
    return l;
}

Creature* Combat::createCharacterOfType(int t, std::string n, std::string tm) {
    Creature *c;
    if (t == 1) {
        c = new Goblin();
    } else if (t == 2) {
        c = new Barbarian();
    } else if (t == 3) {
        c = new ReptilePeople();
    } else if (t == 4) {
        c = new BlueMen();
    } else if (t == 5) {
        c = new TheShadow();
    }
    c->setName(n);
    c->setTeamName(tm);
    return c;
}
