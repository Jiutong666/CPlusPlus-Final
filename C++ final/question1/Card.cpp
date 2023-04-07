#include "Card.h"

#include <iostream>
#include <random>

Card::Card()
{
   std::random_device engine;
   std::uniform_int_distribution<unsigned int> uniform_dist(0, 7);

   this->colour = static_cast<Colour>(uniform_dist(engine));
   this->number = uniform_dist(engine);
}

Card::Card(Colour _colour, int _number)
{
   this->colour = _colour;
   this->number = _number;
}

Card::Card(const Card& other) {
    this->colour = other.colour;
    this->number = other.number;

}

Card::~Card() {
}

Colour Card::getColour() {
   return colour;
}

int Card::getNumber() {
   return number;
}

void Card::setColour(Colour colour) {
   this->colour = colour;
}

void Card::setNumber(int number) {
   this->number = number;
}

bool Card::operator<(const Card& other) const{
   bool retVal = false;
   if(this->colour < other.colour){
      retVal = true;
   }else if((this->colour == other.colour) 
                  && (this->number < other.number)){
      retVal = true;
   }
   return retVal;
}

bool Card::operator==(const Card& other) const{
   return this->number == other.number &&
         this->colour == other.colour;
}

std::string getColourAsString(int colour) {
   // Define some colours as string
   char red[] = "Red";
   char orange[] = "Orange";
   char yellow[] = "Yellow";
   char green[] = "Green";
   char blue[] = "Blue";
   char indigo[] = "Indigo";
   char violet[] = "Violet";
   char unknown[] = "UNKNOWN";

   std::string retVal = "";

   if (colour == RED) {
      retVal = red;
   } else if (colour == ORANGE) {
      retVal =  orange;
   } else if (colour == YELLOW) {
      retVal = yellow;
   } else if (colour == GREEN) {
      retVal = green;
   } else if (colour == BLUE) {
      retVal = blue;
   } else if (colour == INDIGO) {
      retVal = indigo;
   } else if (colour == VIOLET) {
      retVal = violet;
   } else {
      retVal = unknown;
   }

   return retVal;
}

std::ostream& operator<<(std::ostream& os, Card& card){
   os << " (" << getColourAsString(card.getColour()) << ", "
         << card.getNumber() << ") ";

   return os;
}