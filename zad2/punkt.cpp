
#include "punkt.hpp"

punkt::punkt(const punkt &pkt)
    : x(pkt.x), y(pkt.y) {}

punkt::punkt(double x1, double y1)
    : x(x1), y(y1) {}

punkt::punkt() :
x(0), y(0) {}

void punkt::translacja(double v1, double v2) {
    x+=v1;
    y+=v2;
}

void punkt::obrot(punkt p, double kat) {
    this->translacja(-p.X(), -p.Y());
    //std::cout<<"b.x= "<<this->X()<<", b.y()= "<<this->Y()<<"\n";
    double x2, y2;
    double k=(kat*PI)/180.0;
    x2 = x*cos(k) - y*sin(k);
    y2 = x*sin(k) + y*cos(k);
    x=x2; y=y2;
    //std::cout<<"b.x= "<<this->X()<<", b.y()= "<<this->Y()<<"\n";
    this->translacja(p.X(), p.Y());
    //std::cout<<"b.x= "<<this->X()<<", b.y()= "<<this->Y()<<"\n";
}
