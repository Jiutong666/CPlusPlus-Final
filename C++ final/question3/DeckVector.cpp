#include "DeckVector.h"

DeckVector::DeckVector(){
}

DeckVector::~DeckVector(){
	clear();
}

int DeckVector::size(){
	return deck.size();
}

Card DeckVector::get(int index){
	return deck[index];
}

void DeckVector::add(Card&& card){
	deck.push_back(std::move(card));
}

void DeckVector::clear(){
	while (deck.size() != 0) {
		deck.pop_back();
	}
}
