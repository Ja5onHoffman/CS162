//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#ifndef CryingBaby_hpp
#define CryingBaby_hpp

#include "Space.hpp"

class CryingBaby : public Space {
private:
    bool crying; // Interaction changes when baby stops crying
public:
    CryingBaby();
    void setCrying(bool);
    bool getCrying();
    void lookAround();
    void talk();
    void manipulate();
};

#endif
