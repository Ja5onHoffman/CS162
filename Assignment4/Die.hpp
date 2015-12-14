//
// Jason Hoffman
// 11/22/2015
// Assignment 4, CS162

#ifndef __Discworld__Die__
#define __Discworld__Die__


class Die {
    
private:
    int sides;
public:
    Die();
    Die(int);
    void setSides(int);
    int roll();
};


#endif
