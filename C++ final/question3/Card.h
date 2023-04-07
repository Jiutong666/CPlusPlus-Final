
#ifndef CARD_H
#define CARD_H

#include <iostream>

enum Colour {
   RED,
   ORANGE,
   YELLOW,
   GREEN,
   BLUE,
   INDIGO,
   VIOLET
};

class Card {
public:
   Card(Colour colour, int number);
   Card(Card& other);
   Card(Card&& other);
   ~Card();

   Card& operator=(const Card& other);
   Card& operator=(const Card&& other);

   Colour getColour();
   int getNumber();

private:
   Colour colour;
   int number;
};

std::ostream& operator<<(std::ostream& os, Card& card);

#endif // CARD_H
