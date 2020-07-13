#include "lista.hpp"

int main() {
    lista l;
    l.wstaw_poczatek(9);
    l.wstaw_poczatek(10);
    l.wstaw_koniec(12);
    l.wstaw_koniec(18);
    l.wstaw_pozycja(34, 1);
    //l.wstaw_poczatek(10);
    lista l2=l;
    std::cout<<l<<"\n";
    std::cout<<l2<<"\n";
    l2.wstaw_pozycja(14,1);
    std::cout<<l2<<"\n";
    l2.usun_poczatek();
    std::cout<<l2<<"\n";
    l2.usun_poz(2);
    
    //l2.usun_poz(0);
    std::cout<<l2<<"\n";
    
}