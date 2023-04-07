#include "Deck.h"
#include "DeckVector.h"
#include "DeckDeQue.h"
#include <memory>

void printDeckType(Deck* deck){

    //TODO
    if (typeid(*deck) == typeid(DeckDeQue)) {
        std::cout << "Deck implimented using Deque" << std::endl;
    }
    else {
        std::cout << "Deck implimented using Vector" << std::endl;
    }
   
}