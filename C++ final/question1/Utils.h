bool readOneCard(Card& card) {

   //read colour
   Colour colour = RED;
   int number = 0;
   int readColour = 0;
   bool readSuccess = true;

   if(!std::cin.eof()){
      std::cin >> readColour;
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
   }

   if(readSuccess == true){
      card.setColour(colour);
      card.setNumber(number);
   }

   return readSuccess;
}