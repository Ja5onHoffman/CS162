//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162

#include "Stack.hpp"
#include <iostream>

Stack::Stack() {
    head = new StackNode(NULL);
}

void Stack::add(Creature *c) {
    if (head->creature == NULL) {
        head->creature = c;
    } else {
        
        StackNode *newNode = head;
        while (newNode->next != NULL) {
            newNode = newNode->next;
        }
        
        newNode->next = new StackNode(c, newNode);
        
    }
}

void Stack::printStack() {
    StackNode *p = head;
    int ln = 1;
    while (p->next != NULL) {
        std::cout << "Loser #" << ln << ": " << p->creature->getName()
        << " - Team: " << p->creature->getTeamName()
        << ", Points: " << p->creature->getTournamentPoints() << std::endl;
        p = p->next;
        ln++;
    }
    
    std::cout << "Loser #" << ln << ": " << p->creature->getName()
    << " - Team: " << p->creature->getTeamName()
    << ", Points: " << p->creature->getTournamentPoints() << std::endl;
}

Creature* Stack::returnHead() {
    return this->head->creature;
}

std::vector<Creature*> Stack::returnContents() {
    std::vector<Creature*> c;
    StackNode *temp = head;
    while (temp->next != NULL) {
        c.push_back(temp->creature);
        temp = temp->next;
    }
    
    return c;
}

void Stack::remove() {
    if (!head) return;
    
    StackNode *currentNode = head;
    StackNode *garbage = currentNode;
    head = currentNode->prev;
    if (head) {
        head->next = NULL;
    }
    
    delete garbage;
}

Stack::~Stack() {
    StackNode *currentNode = head;
    StackNode *garbage;
    while (currentNode != NULL) {
        garbage = currentNode;
        currentNode = currentNode->next;
        delete garbage;
    }
}