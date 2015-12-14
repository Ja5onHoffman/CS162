//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#ifndef Economy_hpp
#define Economy_hpp

#include "Space.hpp"
#include "CryingBaby.hpp"
#include <string>

class Economy : public Space {
private:
    CryingBaby *baby; // Baby object changes as player interacts
public:
    Economy(CryingBaby*);
    void lookAround();
    void talk();
};

#endif
