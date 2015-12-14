//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#ifndef Space_hpp
#define Space_hpp

#include <iostream>
#include <string>
class Character;

class Space {
protected:
    // Pointers to adjaces spaces
    Space *fwd;
    Space *back;
    Space *left;
    Space *right;
    bool requiresKey;
    Character *character;
    std::string spaceName;
public:
    Space();
    Space(Space*, Space*, Space*, Space*);
    ~Space();
    // Space is first instantiated, then relationship pointers are set up using setLocaiton
    void setLocation(Space*, Space*, Space*, Space*, Character*, std::string);
    bool getRequiresKey();
    Space* getFwd();
    Space* getBack();
    Space* getLeft();
    Space* getRight();
    std::string getSpaceName();
    // virtual functions, two pure virtual
    virtual void talk() = 0;
    virtual void lookAround() = 0;
    virtual void manipulate();
};

#endif