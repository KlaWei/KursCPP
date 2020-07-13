
#include "globalne.hpp"

punkt trojkat::A() {
    return a;
}

punkt trojkat::B() {
    return b;
}

punkt trojkat::C() {
    return c;
}

trojkat::trojkat() :
a(punkt(0,0)), b(punkt(0,1)), c(punkt(1,0)) {}

trojkat::trojkat(punkt p1, punkt p2, punkt p3)
: a(p1), b(p2), c(p3) {
    double d1, d2, d3;
    d1 = odleglosc_pkt(a, b);
    d2 = odleglosc_pkt(a, c);
    d3 = odleglosc_pkt(b, c);
    if(d1+d2<d3 || d1+d3<d2 || d2+d3<d1) {
        throw std::string("Niepoprawny trojkat.");
    }
    if((a.X()==b.X() && b.X()==c.X()) || ((a.Y()==b.Y()) && (b.Y()==c.Y()))) {
        throw std::string("Niepoprawny trojkat.");
    }
}

trojkat::trojkat(const trojkat &tr)
: a(tr.a), b(tr.b), c(tr.c) {}

void trojkat::translacja(double v1, double v2) {
    a.translacja(v1, v2);
    b.translacja(v1, v2);
    c.translacja(v1, v2);
}

void trojkat::obrot(punkt p, double kat) {
    a.obrot(p, kat);
    b.obrot(p, kat);
    c.obrot(p, kat);
}

double trojkat::obwod() {
    return odleglosc_pkt(a, b) + odleglosc_pkt(a, c) + odleglosc_pkt(b, c);
}

double trojkat::pole() {
    double d1, d2, d3, s;
    d1 = odleglosc_pkt(a, b);
    d2 = odleglosc_pkt(a, c);
    d3 = odleglosc_pkt(b, c);
    s = (d1+d2+d3)/2;
    return sqrt(s*(s-d1)*(s-d2)*(s-d3));
}

punkt trojkat::srodek() {
    return punkt((a.X()+b.X()+c.X())/3, (a.Y(), b.Y(), c.Y())/3);
}

void test_trojkat() {
    trojkat t1, t2;
    
}
