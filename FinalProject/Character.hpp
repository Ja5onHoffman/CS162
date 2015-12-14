//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#ifndef Character_hpp
#define Character_hpp

#include <vector>
#include <string>
class Space;

class Character {
    
protected:
    std::string name;
    bool hasCKey; // cockpit key
    bool hasKey; // secret cargo key
    Space *currentSpace;
    std::vector<std::string> objects; // vector to hold objects
public:
    Character();
    void setName(std::string);
    void setHasKey(bool);
    void setHasCKey(bool);
    void setCurrentSpace(Space*);
    Space* getCurrentSpace();
    bool getHasKey();
    bool getHasCKey();
    bool getTalked();
    std::string getName();
    bool objectSearch(std::string); // search objects vector
    // movement
    void moveFwd();
    void moveBack();
    void moveLeft();
    void moveRight();
    void addObject(std::string);
};

#endif