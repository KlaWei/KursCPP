#ifndef kolejka_hpp
#define kolejka_hpp

#include <iostream>
#include <initializer_list>

class kolejka {
public:
    kolejka(int n);
    kolejka();
    kolejka(const kolejka& k);
    kolejka(kolejka&& k);
    kolejka(std::initializer_list<std::string> lista);
    ~kolejka();
    kolejka& operator=(kolejka &k);
    kolejka& operator=(kolejka &&k);
    void wstaw(std::string s);
    std::string pobierz();
    std::string sprawdz();
    int rozmiar();
    int pojemnosc_k();
    void wypisz();
private:
    int pojemnosc;
    int ile;
    int poczatek;
    int koniec;
    std::string *tab;
};

#endif
