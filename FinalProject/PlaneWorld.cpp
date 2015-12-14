//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "PlaneWorld.hpp"

PlaneWorld::PlaneWorld() {
    
    // First instantiate all Space objects
    LookingOutside *lookingOutside = new LookingOutside();
    Cockpit *cockpit = new Cockpit();
    CaptainSeat *captainSeat = new CaptainSeat();
    FOSeat *foSeat = new FOSeat();
    Forward *forward = new Forward();
    FrontGalley *frontGalley = new FrontGalley();
    FrontLav *frontLav = new FrontLav();
    FirstClass *firstClass = new FirstClass();
    JustinBieber *justinBieber = new JustinBieber();
    ArnoldS *arnoldS = new ArnoldS();
    CryingBaby *cryingBaby = new CryingBaby();
    Economy *economy = new Economy(cryingBaby);
    DroolingSleeper *droolingSleeper = new DroolingSleeper();
    Back *back = new Back();
    BackLav *backLav = new BackLav();
    DrinkCart *drinkCart = new DrinkCart();
    SecretCargo *secretCargo = new SecretCargo();
    
    // Instantiate Character and starting point
    this->character = new Character();
    this->character->setCurrentSpace(backLav);
    
    // Then set up Space pointers
    lookingOutside->setLocation(NULL, cockpit, NULL, NULL, character, "looking out the windshield");
    cockpit->setLocation(lookingOutside, forward, captainSeat, foSeat, character, "in the cockpit");
    captainSeat->setLocation(NULL, NULL, NULL, cockpit, character, "sitting with the captain");
    foSeat->setLocation(NULL, NULL, cockpit, NULL, character, "sitting with the first officer");
    forward->setLocation(cockpit, firstClass, frontLav, frontGalley, character, "in front FA area");
    frontLav->setLocation(NULL, NULL, NULL, forward, character, "in the front lav");
    frontGalley->setLocation(NULL, NULL, forward, NULL, character, "in the front galley");
    firstClass->setLocation(forward, economy, arnoldS, justinBieber, character, "in first class");
    arnoldS->setLocation(NULL, NULL, NULL, firstClass, character, "sitting next to Arnold Schwarzenegger");
    justinBieber->setLocation(NULL, NULL, firstClass, NULL, character, "sitting next to Justin Bieber");
    economy->setLocation(firstClass, back, cryingBaby, droolingSleeper, character, "in economy class");
    cryingBaby->setLocation(NULL, NULL, NULL, economy, character, "sitting next to a crying baby");
    droolingSleeper->setLocation(NULL, NULL, economy, NULL, character, "sitting next to a drooling sleeper");
    back->setLocation(economy, secretCargo, backLav, drinkCart, character, "in the back with the flight attendants");
    backLav->setLocation(NULL, NULL, NULL, back, character, "in the back lav");
    drinkCart->setLocation(NULL, NULL, back, NULL, character, "at the rear drink cart");
    secretCargo->setLocation(back, NULL, NULL, NULL, character, "in the secret cargo area");
}

Character* PlaneWorld::getCharacter() {
    return this->character;
}