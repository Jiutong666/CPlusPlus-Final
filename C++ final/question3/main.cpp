/*                                           */
/* DO NOT MOFIFY ANY CODE IN THIS FILE       */
/*                                           */
#include "Deck.h"
#include "DeckVector.h"
#include "DeckDeQue.h"

#include <iostream>
#include <memory>

#include "Utils.h"

bool readOneCard(Colour& colour, int& number);

int main(int argc, char** argv) {

   Deck* deck = nullptr;

   // read a number from terminal that indicate what ADT implementation 
   // to be used for storing cards. If the input is $0$, then ``DeckVector'' 
   // object will be used, else if  $1$, a ``DeckDeQue'' object will be used.
   int deckType = 0;
   std::cout << "Enter Deck Type (0 - for Vector, 1 - for DeQue): " << std::endl;
   std::cin >> deckType;

   if(deckType == 0){
      deck = new DeckVector();
   }else{
      deck = new DeckDeQue();
   }


   // Reading cards from the standard input
   while(!std::cin.eof()){
      Colour colour;
      int number;
      bool success = readOneCard(colour, number);
      if(success){
         Card card(colour, number);
         deck->add(std::move(card));
      }
   }

   //print the size of the deck and the cards in it.
   std::cout << "Size of deck: " << deck->size() << std::endl;
   std::cout << "Cards in Deck: " << std::endl;
   for(int i = 0; i != deck->size(); ++i){
      Card temp = deck->get(i);
      std::cout << " " << temp << std::endl;
   }

   //print some details about the underlying implementation of the
   // deck. If deck is an DeckVector object, then print "Deck implemented 
   // using Vector". Else if deck is an DeckDeQue object, then print 
   //"Deck implemented using Deque.
   printDeckType(deck);

   delete deck;
   return EXIT_SUCCESS;
}


bool readOneCard(Colour& colour, int& number) {

   int readColour = 0;
   bool readSuccess = true;

   std::cin >> readColour;
   if(!std::cin.eof()){
      
      if(readColour == 0){
         colour = RED;
      }else if (readColour == 1){
         colour = ORANGE;
      }else if (readColour == 2){
         colour = YELLOW;
      }else if (readColour == 3){
         colour = GREEN;
      }else if (readColour == 4){
         colour = BLUE;
      }else if (readColour == 5){
         colour = INDIGO;
      }else if (readColour == 6){
         colour = VIOLET;
      }else{
         readSuccess = false;
         std::cout << "Incorrect color try again!" << std::endl;
      }

      //read number
      std::cin >> number;
      if(number < 1 || number > 7){
         readSuccess = false;
         std::cout << "Incorrect number try again!" << std::endl;
      }
   }else{
       readSuccess = false;
   }

   return readSuccess;
}