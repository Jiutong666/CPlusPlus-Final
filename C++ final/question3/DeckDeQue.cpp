#include "DeckDeQue.h"

DeckDeQue::DeckDeQue(){	
}

DeckDeQue::~DeckDeQue(){
	clear();
}

int DeckDeQue::size(){
	return deck.size();
}

Card DeckDeQue::get(int index){
	return deck[index];
}

void DeckDeQue::add(Card&& card){
	deck.push_back(std::move(card));
}

void DeckDeQue::clear(){
	while (deck.size() != 0) {
		deck.pop_front();
	}
}
