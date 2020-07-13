#include <iostream>
#include "wyrazenie.hpp"
#include "operatory1arg.hpp"
#include "operatory2arg.hpp"

int main() {
    zmienna::dodaj_zmienna("x", 2);
    wyrazenie *w = new odwrot(new Sin(new liczba(8)));
    std::cout<<w->opis()<<" wartosc: "<<w->oblicz()<<"\n";
    
    //wyrazenie *w2 = new zmienna("x");
    //std::cout<<w2->opis()<<" wartosc: "<<w2->oblicz()<<"\n";
    
    //wyrazenie *w3 = new odejmij(new pi(), new dodaj(new liczba(2), new mnoz(new zmienna("x"), new liczba(7))));
    //std::cout<<w3->opis()<<" wartosc: "<<w3->oblicz()<<"\n";
    
    wyrazenie *w1=new dziel(new mnoz(new odejmij(new zmienna("x"), new liczba(1)), new zmienna("x")), new liczba(2));
    std::cout<<w1->opis()<<"\n";
    wyrazenie *w2=new dziel(new dodaj(new liczba(3), new liczba(5)), 
                  new dodaj(new liczba(2), new mnoz(new zmienna("x"), new liczba(7))));
    std::cout<<w2->opis()<<"\n";
    wyrazenie *w3=new odejmij(new dodaj(new liczba(2), new mnoz(new zmienna("x"), new liczba(7))), 
                new dodaj(new mnoz(new zmienna("x"), new liczba(3)), new liczba(5)));
    std::cout<<w3->opis()<<"\n";
    wyrazenie *w4=new dziel(new Cos(new mnoz(new dodaj(new zmienna("x"), new liczba(1)), new zmienna("x"))), 
                  new potega(new e(), new potega(new zmienna("x"), new liczba(2))));
    std::cout<<w4->opis()<<"\n";
    wyrazenie *w5 = new mnoz(new dodaj(new liczba(5), new liczba(4)), new zmienna("y"));
    std::cout<<w5->opis()<<"\n";
    
    for (double i=0; i<=1; i+=0.01) {
        zmienna::zmien_wartosc("x", i);
        std::cout<<"Wartosci dla x="<<zmienna::pobierz_wartosc("x")<<":\n";
        std::cout<<"w1 = "<<w1->oblicz()<<"\n";
        std::cout<<"w2 = "<<w2->oblicz()<<"\n";
        std::cout<<"w3 = "<<w3->oblicz()<<"\n";
        std::cout<<"w4 = "<<w4->oblicz()<<"\n";
    }
}