/*                                           */
/* DO NOT MOFIFY ANY CODE IN THIS FILE       */
/*                                           */

#include <exception>
#include <iostream>
#include <memory>
#include <iomanip>
#include "Force.h"

void readForceFromTerminal(Force& f);

int main(){
    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */

    // Create a force f1 with fx = 2.5, fy = 3.5 and fz=2.5
    Force f1(2.5, 3.5, 2.5);
    std::cout << "F1 = " << f1 << std::endl;

    // Read a force from the terminal
    Force f2;
    readForceFromTerminal(f2);

    // Print f2
    std::cout << "F2 = " << f2 << std::endl;

    //compare and to see which force is larger
    if(f1>f2){
        std::cout << "f1" << " > " << "f2" << std::endl;
    }else{
        std::cout << "f1" << " <= " << "f2" << std::endl;
    }

    // Compute resultant force
    Force Fres;
    Fres = std::move(f1+f2);

    // Print the resultent force
    std::cout << "Fres = " << Fres << std::endl;

}

void readForceFromTerminal(Force& f){

    std::cout << "Enter a Force [fx fy fz]: ";
    std::cin >> f["fx"]; 
    std::cin >> f["fy"]; 
    std::cin >> f["fz"]; 
 
    std::cout << std::endl;
}