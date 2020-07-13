#ifndef trojkat_hpp
#define trojkat_hpp

#include "punkt.hpp"

class trojkat {
    punkt a, b, c;
    public:
    trojkat();
    trojkat(punkt p1, punkt p2, punkt p3);
    trojkat(const trojkat &tr);
    punkt A();
    punkt B();
    punkt C();
    void translacja(double v1, double v2);
    void obrot(punkt p, double kat);
    double obwod();
    double pole();
    punkt srodek();
};

#endif /* trojkat_hpp */
