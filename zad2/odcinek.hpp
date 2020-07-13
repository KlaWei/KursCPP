
#ifndef odcinek_hpp
#define odcinek_hpp

#include "punkt.hpp"

class odcinek {
    punkt a, b;
    public:
    odcinek();
    odcinek(punkt p1, punkt p2);
    odcinek(const odcinek &odc);
    punkt A();
    punkt B();
    void translacja(double v1, double v2);
    void obrot(punkt p, double kat);
    bool nalezy_do_odc(punkt p);
    punkt srodek();
    double dlugosc();
};

#endif /* odcinek_hpp */
