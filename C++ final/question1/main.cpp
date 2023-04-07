
/*                                           */
/* DO NOT MOFIFY ANY CODE IN THIS FILE       */
/*                                           */

#include "BST.h"

#include <iostream>
#include <fstream>
#include <string>

#include "Card.h"
#include "Utils.h"


int main(void) {
   BST<Card>* bst = new BST<Card>();

   // Reading cards from the standard input
   while(!std::cin.eof()){
      if(!std::cin.eof()){
         Card card;
         bool success = readOneCard(card);
         if(success){
            bst->add(card);
         }
      }
   }

   //Print the depth of the BST
   //  maximum number of node one should traverses 
   //  to get to a leaf node (leaf node: both left and right is nullptr)
   std::cout << "Depth of BST: ";
   std::cout << bst->depth() << std::endl;

   //print the cards in BST in order 
   // functions required to determine the order is given to you.
   std::cout << "Sorted cards:" << std::endl;
   bst->dfs();

   delete bst;
   std::cout << "Done" << std::endl;

   return EXIT_SUCCESS;
}