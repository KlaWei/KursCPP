
#include "globalne.hpp"


odcinek::odcinek() :
a(punkt(0,0)), b(punkt(0,1)) {}

odcinek::odcinek(punkt p1, punkt p2)
: a(p1), b(p2) {
    if(a.X()==b.X() && a.Y()==b.Y())
    throw std::string("Wspolrzedne odcinka takie same.");
}

odcinek::odcinek(const odcinek &odc) :
a(odc.a), b(odc.b) {}

punkt odcinek::A() {
    return a;
}

punkt odcinek::B() {
    return b;
}

void odcinek::translacja(double v1, double v2) {
    a.translacja(v1, v2);
    b.translacja(v1, v2);
}

void odcinek::obrot(punkt p, double kat) {
    a.obrot(p, kat);
    b.obrot(p, kat);
}

bool odcinek::nalezy_do_odc(punkt p) {
    if((odleglosc_pkt(a, p) + odleglosc_pkt(b, p))==odleglosc_pkt(a, b))
    return true;
    return false;
}

punkt odcinek::srodek() {
    return punkt((a.X()+b.X())/2, (a.Y()+b.Y())/2);
}

double odcinek::dlugosc() {
    return odleglosc_pkt(a, b);
}
