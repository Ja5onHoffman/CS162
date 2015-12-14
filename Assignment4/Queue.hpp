//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162

#ifndef __LabSix__Queue__
#define __LabSix__Queue__

#include <string>
#include "Creature.hpp"

class Queue {
    int teamPoints;
protected:
    struct QueueNode {
        friend class Queue;
        Creature *creature;
        QueueNode *next;
        QueueNode *prev;
        QueueNode(Creature *c, QueueNode* prevNode = NULL, QueueNode *nextNode = NULL) {
            creature = c;
            next = nextNode;
            prev = prevNode;
        }
    };
    QueueNode *front;
    QueueNode *back;
public:
    Queue();
    ~Queue();
    Creature* getFront();
    void add(Creature*);
    void removeFront();
    void frontToBack();
    int calculatePoints();
    bool isEmpty();
};

#endif
