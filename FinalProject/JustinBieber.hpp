//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#ifndef JustinBieber_hpp
#define JustinBieber_hpp

#include "Space.hpp"

class JustinBieber : public Space {
private:
    bool sad;
public:
    JustinBieber();
    void lookAround();
    void talk();
    void manipulate();
};

#endif