//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162

#include "Queue.hpp"

Queue::Queue() {
    front = new QueueNode(NULL);
    back = front;
    this->teamPoints = 0;
}

Creature* Queue::getFront() {
    return this->front->creature;
}

void Queue::add(Creature *c) {
    if (front->creature == NULL) {
        front->creature = c;
        back = front;
    } else {
        QueueNode *newNode = front;
        while (newNode->next != NULL) {
            newNode = newNode->next;
        }
        newNode->next = new QueueNode(c, newNode);
        back = newNode->next;
    }
}

// FIFO
void Queue::removeFront() {
    if (!front) return;
    
    QueueNode *garbage = front;
    front = garbage->next;
    
    if (!front) {
        back = front;
    }
    
    if (front) {
        front->prev = NULL;
        if (front == back) {
            back->next = NULL;
        }
    }
    
    if (!front) {
        
    }
    
    delete garbage;
}

int Queue::calculatePoints() {
    QueueNode *pNode = front;
    while (pNode->next != NULL) {
        this->teamPoints += pNode->creature->getTournamentPoints();
        pNode = pNode->next;
    }
    
    if (pNode->next != NULL) {
        pNode = pNode->next;
    }

    this->teamPoints += pNode->creature->getTournamentPoints();
    return this->teamPoints;
}

void Queue::frontToBack() {
    if (!front) return;
    
    this->add(front->creature);
    this->removeFront();
}

bool Queue::isEmpty() {
    return !front ? true : false;
}

Queue::~Queue() {
    QueueNode *currentNode = front;
    QueueNode *garbage;
    while (currentNode != NULL) {
        garbage = currentNode;
        currentNode = currentNode->next;
        delete garbage;
    }
}