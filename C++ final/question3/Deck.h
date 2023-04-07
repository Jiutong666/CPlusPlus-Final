/*                                           */
/* DO NOT MOFIFY ANY CODE IN THIS FILE       */
/*                                           */

#ifndef DECK_H
#define DECK_H 

#include <istream>
#include <string>
#include <vector>

#include "Card.h"

#define MAXIMUM_DECK_SIZE    50

/**
Abstract class that represent a deck of Red7 cards
Should hold a list of Cards [not pointers]
 */
class Deck {
public:

    /*   INSTRUCTIONS:                                  */
    /*   1) DO NOT REMOVE ANY FUNCTION IN THIS SECTION  */
    /*   2) DO NOT CHANGE THE INPUTS AND OUTPUTS OF     */
    /*      THE FUNCTIONS DECLARED IN THIS SECTION      */

    virtual ~Deck() {};

    /**
    * Return the current size of the Deck.
    */
    virtual int size() = 0;

    /**
    * Get a copy of the card at the given index.
    */
    //Contract:
    // index should be valid - in range [0, size)
    virtual Card get(int index) = 0;

    /**
    * Add a card to the bottom of the deck
    * note right hand reference. card should be moved
    */
    virtual void add(Card&& card) = 0;


    /**
    * Removes all cards from the deck.
    * Delete these card
    */
    virtual void clear() = 0;

private:


};

#endif // DECK_H
