#ifndef WYRAZENIE_H
#define WYRAZENIE_H

#include <string>
#include <cmath>
#include <vector>
#include <utility>

class wyrazenie {
    public:
        virtual double oblicz()=0;
        virtual std::string opis()=0;
        virtual int priorytet()=0;
};

class stala : public wyrazenie {
    public:
        stala() {}
};

class pi : public stala {
    public:
        pi() {}
        double oblicz() { return M_PI; }
        std::string opis() { return "pi"; }
        int priorytet() { return 1; }
};

class e : public stala {
    public:
        e() {}
        double oblicz() { return M_E; }
        std::string opis() { return "e"; }
        int priorytet() { return 1; }
};

class liczba : public wyrazenie  {
    double wartosc;
    public:
        liczba(double x);
        double oblicz();
        std::string opis();
        int priorytet() { return 1; }
};

class zmienna : public wyrazenie {
    std::string nazwa;
    static std::vector< std::pair<std::string, double> > zmienne;
    public:
        zmienna(std::string s);
        double oblicz();
        std::string opis();
        static void dodaj_zmienna(std::string s, double x);
        static double pobierz_wartosc(std::string s);
        static void zmien_wartosc(std::string s, double x);
        int priorytet() { return 1; }
};

#endif