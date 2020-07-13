#ifndef WYMIERNA_H
#define WYMIERNA_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

namespace obliczenia {
    
class wyjatek_wymierny {};

class dzielenie_przez_0 : public wyjatek_wymierny {
  public:
    dzielenie_przez_0() {}
    const char* what() { return "Dzielenie przez 0."; }
};

class przekroczenie_zakresu : public wyjatek_wymierny {
  public:
    przekroczenie_zakresu() {}  
    const char* what() { return "Przekrocznie zakresu."; }
};

/*class dzielenie_przez_0 : public std::exception {
    public:
        dzielenie_przez_0() throw() {}
        const char* what() const throw() { return "Dzielenie przez 0."; }
};

class przekroczenie_zakresu : public std::exception {
    public:
        przekroczenie_zakresu() throw() {}
        const char* what() const throw() { return "Przekroczenie zakresu."; }
};*/

class wymierna {
    int licz, mian;
    static int gcd(int l, int m);
    static int lcm(int n, int m);
    public:
        wymierna(int licznik, int mianownik) throw(dzielenie_przez_0, przekroczenie_zakresu);
        wymierna(int licznik);
        int mianownik();
        int licznik();
        friend wymierna operator - (const wymierna &w1, const wymierna &w2) throw(przekroczenie_zakresu);
        friend wymierna operator + (const wymierna &w1, const wymierna &w2) throw(przekroczenie_zakresu);
        friend wymierna operator * (const wymierna &w1, const wymierna &w2) throw(przekroczenie_zakresu);
        friend wymierna operator / (const wymierna &w1, const wymierna &w2) throw(dzielenie_przez_0, przekroczenie_zakresu);
        friend std::ostream& operator << (std::ostream &wy, const wymierna &w);
        
        friend wymierna operator ! (const wymierna &w);
        friend wymierna operator - (const wymierna &w);
        explicit operator int();
        operator double();
        
};
}

#endif