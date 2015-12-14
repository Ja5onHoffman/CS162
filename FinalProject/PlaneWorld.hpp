//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#ifndef PlaneWorld_hpp
#define PlaneWorld_hpp

#include "LookingOutside.hpp"
#include "Cockpit.hpp"
#include "CaptainSeat.hpp"
#include "FOSeat.hpp"
#include "Forward.hpp"
#include "FrontGalley.hpp"
#include "FrontLav.hpp"
#include "FirstClass.hpp"
#include "JustinBieber.hpp"
#include "ArnoldS.hpp"
#include "Economy.hpp"
#include "CryingBaby.hpp"
#include "DroolingSleeper.hpp"
#include "Back.hpp"
#include "BackLav.hpp"
#include "DrinkCart.hpp"
#include "SecretCargo.hpp"
#include "Character.hpp"

// PlaneWorld contains "world" where all pointers will be arranged

class PlaneWorld {
private:
    Character *character;
public:
    Character* getCharacter();
    PlaneWorld();
};

#endif
