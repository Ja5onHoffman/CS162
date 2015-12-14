//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162

#ifndef __LabSix__StackLike__
#define __LabSix__StackLike__

#include <string>
#include <iostream>
#include <vector>
#include "Creature.hpp"

class Stack {
protected:
    struct StackNode {
        Creature *creature;
        StackNode *next;
        StackNode *prev;
        StackNode(Creature *c, StackNode *prevNode = NULL, StackNode *nextNode = NULL) {
            creature = c;
            next = nextNode;
            prev = prevNode;
        }
    };
    StackNode *head;
    
public:
    Stack();
    ~Stack();
    Creature* returnHead();
    std::vector<Creature*> returnContents();
    void add(Creature*);
    void printStack();
    void remove();
};



#endif
