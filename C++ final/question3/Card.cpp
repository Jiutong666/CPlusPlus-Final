#include "Card.h"

#include <iostream>


Card::Card(Colour _colour, int _number)
{
   this->colour = _colour;
   this->number = _number;
}

Card::Card(Card& other) {
   this->colour = other.colour;
   this->number = other.number;
}

Card::Card(Card&& other) {
   this->colour = other.colour;
   this->number = other.number;
}

Card& Card::operator=(const Card& other){
   this->colour = other.colour;
   this->number = other.number;
   return *this;
}

Card& Card::operator=(const Card&& other){
   this->colour = other.colour;
   this->number = other.number;
   return *this;
}


Card::~Card() {
}

Colour Card::getColour() {
   return colour;
}

int Card::getNumber() {
   return number;
}

std::ostream& printColourAsString(std::ostream& output, int colour) {
   // Define some colours as string
   char red[] = "Red";
   char orange[] = "Orange";
   char yellow[] = "Yellow";
   char green[] = "Green";
   char blue[] = "Blue";
   char indigo[] = "Indigo";
   char violet[] = "Violet";
   char unknown[] = "UNKNOWN";

   if (colour == RED) {
      output << red;
   } else if (colour == ORANGE) {
      output << orange;
   } else if (colour == YELLOW) {
      output << yellow;
   } else if (colour == GREEN) {
      output << green;
   } else if (colour == BLUE) {
      output << blue;
   } else if (colour == INDIGO) {
      output << indigo;
   } else if (colour == VIOLET) {
      output << violet;
   } else {
      output << unknown;
   }

   return output;
}

std::ostream& operator<<(std::ostream& os, Card& card){
   os << "("; 
   printColourAsString( os, card.getColour());
   os << ", " << card.getNumber() << ")";


   return os;
}
