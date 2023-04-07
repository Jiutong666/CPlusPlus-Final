#include "Force.h"
#include <iomanip>

/*                                           */
/*         YOU MAY ADD YOUR CODE HERE        */
/*                                           */

Force::Force(){
    this->fx=0;
    this->fy = 0;
    this->fz = 0;
}
Force::~Force(){
}

Force::Force(double x, double y, double z){
    this->fx = x;
    this->fy = y;
    this->fz = z;
}

double& Force::operator[](std::string str){
    if(str.compare("fx")==0){
        return fx;
    }else if(str.compare("fy")==0){
        return fy;
    }else{
        return fz;
    }
}

Force Force::operator+(const Force& f)const{
    double x = this->fx+f.fx;
    double y = this->fy+f.fy;
    double z = this->fz+f.fz;
    return Force(x,y,z);
}

bool Force::operator >(const Force& f) const{
    double fa = this->fx*this->fx + this->fy*this->fy + this->fz*this->fz;
    double fb = f.fx*f.fx + f.fy*f.fy + f.fz*f.fz;
    if(fa>fb) return true;
    else return false;
}

//__________________________________________________________//

/*                                           */
/* DO NOT MOFIFY ANY CODE IN THIS FUNCTION   */
/*                                           */
std::ostream& operator<<(std::ostream& os, Force& f){
    os << std::fixed << std::setprecision(2)  << f["fx"];
    os << "i + ";
    os << std::fixed << std::setprecision(2)  << f["fy"];
    os << "j + ";
    os << std::fixed << std::setprecision(2)  << f["fz"];
    os << "k";

    return os;
}
