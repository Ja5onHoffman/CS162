//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#ifndef SecretCargo_hpp
#define SecretCargo_hpp

#include "Space.hpp"

class SecretCargo : public Space {
public:
    SecretCargo();
    void lookAround();
    void manipulate();
    void talk();
};

#endif
