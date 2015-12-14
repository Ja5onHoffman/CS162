//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#ifndef Cockpit_hpp
#define Cockpit_hpp

#include "Space.hpp"

class Cockpit : public Space {

public:
    Cockpit();
    void lookAround();
    void talk();
};

#endif
