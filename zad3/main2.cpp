#include "kolejka.hpp"

int main() {
    kolejka *k = new kolejka();
    k->wstaw("a");
    k->wstaw("b");
    k->wstaw("c");
    std::cout<<"[K] = "; k->wypisz();
    std::string napis = k->pobierz();
    std::cout<<"pobrany z [K] = "<<napis<<"\n";
    std::cout<<"[K] = "; k->wypisz();
    
    kolejka *a = new kolejka({"aaa", "bbb", "ccc", "ddd", "eee"});
    std::cout<<"[A] = "; a->wypisz();
    napis = a->pobierz();
    std::cout<<"pobrany z [A]: "<<napis<<"\n";
    std::cout<<"[A] = "; a->wypisz();
    
    *k=*a; // konstr kopiujacy
    std::cout<<"  kopiuj [K] do [A]\n";
    std::cout<<"  [K] = "; k->wypisz();
    std::cout<<"  [A] = "; a->wypisz();
    a->wstaw("rr");
    a->wypisz();
    kolejka *k2=new kolejka(std::move(*k));
    //k= std::move(k2);
    k2->wypisz();
    k->wypisz();
    a->wypisz();
    *k2 = std::move(*a);
    k2->wypisz();
    a->wypisz();
}