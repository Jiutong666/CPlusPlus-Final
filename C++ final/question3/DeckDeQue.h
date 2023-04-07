#ifndef DECK_DEQUE_H
#define DECK_DEQUE_H 

#include "Deck.h"
#include <deque>

class DeckDeQue :public Deck {
public:
    DeckDeQue();
    ~DeckDeQue();
    int size();
    Card get(int index);
    void add(Card&& card);
    void clear();
    

private:
    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */
    std::deque<Card> deck;

};

#endif //DECK_DEQUE_H 