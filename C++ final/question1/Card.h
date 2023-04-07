
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
   Card(); 
   Card(Colour colour, int number);
   Card(const Card& other);
   ~Card();

   Colour getColour() ;
   int getNumber() ;

   void setColour(Colour colour) ;
   void setNumber(int number) ;

   bool operator<(const Card& other) const;  
   bool operator==(const Card& other) const;

   friend std::ostream& operator<<(std::ostream& os, Card& card);

private:
   Colour colour;
   int number;
};


#endif // CARD_H
