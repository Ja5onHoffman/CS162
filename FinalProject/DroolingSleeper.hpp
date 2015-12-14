//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#ifndef DroolingSleeper_hpp
#define DroolingSleeper_hpp

#include "Space.hpp"

class DroolingSleeper : public Space {
protected:
    bool awake; // Interaction changes when sleeper is awake
public:
    void setAwake(bool);
    void lookAround();
    void talk();
    void manipulate();
};

#endif
