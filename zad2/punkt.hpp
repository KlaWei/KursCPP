#ifndef punkt_hpp
#define punkt_hpp

#include <iostream>
#include <math.h>
#include <stdbool.h>

#define PI 3.14159265

const double eps=1e-7;

class punkt {
    double x, y;
    
    public:
    punkt();
    punkt(double x1, double y1);
    punkt(const punkt &pkt);
    void translacja(double v1, double v2);
    void obrot(punkt p, double kat);
    double X() { return x; }
    double Y() { return y; }
};

#endif /* punkt_hpp */
