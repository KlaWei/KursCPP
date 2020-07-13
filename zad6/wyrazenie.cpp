#include "wyrazenie.hpp"

liczba::liczba(double x) : wartosc(x) {}

double liczba::oblicz() {
    return wartosc;
}

std::string liczba::opis() {
    return std::to_string(wartosc);
}

std::vector< std::pair<std::string, double> > zmienna::zmienne;

zmienna::zmienna(std::string s) : nazwa(s) {}

double zmienna::oblicz() {
    return pobierz_wartosc(nazwa);
}

std::string zmienna::opis() {
    return nazwa;
}

void zmienna::dodaj_zmienna(std::string s, double x) {
    zmienne.push_back(std::make_pair(std::string(s), x));
}

double zmienna::pobierz_wartosc(std::string s) {
    std::vector<std::pair<std::string, double> >::iterator it;
    
    for (it=zmienne.begin();it!=zmienne.end();it++) {
        if(it->first==s) break;
    }
    return it->second;
}

void zmienna::zmien_wartosc(std::string s, double x) {
    std::vector<std::pair<std::string, double> >::iterator it;
    
    for (it=zmienne.begin();it!=zmienne.end();it++) {
        if(it->first==s) break;
    }
    it->second=x;
}

