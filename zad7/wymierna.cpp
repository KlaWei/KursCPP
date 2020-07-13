#include "wymierna.hpp"
#include <climits>
namespace obliczenia {
    
int wymierna::gcd(int l, int m) {
    l=std::abs(l);
    m=std::abs(m);
    int a=0,b=0,c=0;
    if(l>m) {
        a = l;
        b = m;
    }
    else {
        a = m;
        b = l;
    }
    while (b>0) {
        c = (int)a%b;
        a = b;
        b = c;
    }
    return a;
}

int wymierna::lcm(int n, int m) {
    return (n/wymierna::gcd(n,m))*m;
}

int wymierna::mianownik() {
    return mian;
}

int wymierna::licznik() {
    return licz;
}

wymierna::wymierna(int licznik, int mianownik) throw(dzielenie_przez_0, przekroczenie_zakresu) {
    if(mianownik==0) {
        throw dzielenie_przez_0();
    }
    if((licznik<0 && mianownik<0) || (licznik>0 && mianownik<0)) {
        licznik = -1*licznik;
        mianownik = -1*mianownik;
    }
    if(mianownik<0) throw przekroczenie_zakresu();
    int d = wymierna::gcd(licznik, mianownik);
    licz=licznik/d;
    mian=mianownik/d;
}

std::ostream& operator << (std::ostream &wy, const wymierna &w) {
    wy << (double)w.licz/w.mian;
    return wy;
}

wymierna operator ! (const wymierna &w) {
    if(w.licz==0) throw dzielenie_przez_0();
    if(w.licz<0) {
        return wymierna(-1*w.mian, -1*w.licz);
    }
    return wymierna(w.mian, w.licz);
}

wymierna operator - (const wymierna &w) {
    return wymierna(-1*w.licz, w.mian);
}

wymierna operator - (const wymierna &w1, const wymierna &w2) throw(przekroczenie_zakresu) {
    int l = wymierna::lcm(w1.mian, w2.mian);
    int l1 = w1.licz*(l/w1.mian), l2 = w2.licz*(l/w2.mian);
    if(l2<0 && l1 > INT_MAX + l2) {
        throw przekroczenie_zakresu();
    }
    if(l2>0 && l1 < INT_MIN + l2) {
        throw przekroczenie_zakresu();
    }
    return wymierna(l1-l2, l);
}

wymierna operator + (const wymierna &w1, const wymierna &w2) throw(przekroczenie_zakresu) {
    int l = wymierna::lcm(w1.mian, w2.mian);
    int l1 = w1.licz*(l/w1.mian), l2 = w2.licz*(l/w2.mian);
    if(l2<0 && l1 < INT_MIN - l2) {
        throw przekroczenie_zakresu();
    }
    if(l2>0 && l1 > INT_MAX - l2) {
        throw przekroczenie_zakresu();
    }
    return wymierna(l1+l2, l);
}

wymierna operator * (const wymierna &w1, const wymierna &w2) throw(przekroczenie_zakresu) {
    int d1 = wymierna::gcd(w1.mian, w2.licz);
    int d2 = wymierna::gcd(w2.mian, w1.licz);
    wymierna pom1(w1.licz/d2, w1.mian/d1);
    wymierna pom2(w2.licz/d1, w2.mian/d2);
    
    if(pom1.licz > INT_MAX/pom2.licz) throw przekroczenie_zakresu();
    if(pom1.mian > INT_MAX/pom2.mian) throw przekroczenie_zakresu();
    
    return wymierna(pom1.licz*pom2.licz, pom1.mian*pom2.mian);
}

wymierna operator / (const wymierna &w1, const wymierna &w2) throw(dzielenie_przez_0, przekroczenie_zakresu) {
    if(w2.licz==0) throw dzielenie_przez_0();
    return w1*(!w2);
}

wymierna::operator int() {
    //std::cout<<"op int\n";
    return int(licz/mian);
}

wymierna::operator double() {
    return double(licz/mian);
}
}
