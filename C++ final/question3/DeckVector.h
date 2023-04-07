#ifndef DECK_VECTOR_H
#define DECK_VECTOR_H 

#include "Deck.h"
#include <vector>

class DeckVector :public Deck {
public:
    DeckVector();
    ~DeckVector();
    int size();
    Card get(int index);
    void add(Card&& card);
    void clear();

private:
    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */
    std::vector<Card> deck;

};

#endif //DECK_VECTOR_H 