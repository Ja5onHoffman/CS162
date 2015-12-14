//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#ifndef CaptainSeat_hpp
#define CaptainSeat_hpp

#include "Space.hpp"

class CaptainSeat : public Space {
protected:
    bool hasCoffee; // Needs coffee before he'll talk to you
public:
    CaptainSeat();
    void lookAround();
    void talk();
    void manipulate();
};

#endif
