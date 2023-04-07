#ifndef FORCE_H
#define FORCE_H


#include <exception>
#include <iostream>

class Force
{

public:
    Force();
    ~Force();
    Force(double x, double y, double z);
    double& operator[](std::string str);
    Force operator+(const Force& f) const;
    bool operator >(const Force& f) const;

private:
    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */
    double fx;
    double fy;
    double fz;
};

std::ostream& operator<<(std::ostream& os, Force& f);

#endif //FORCE_H