#include "kolejka.hpp"

int main() {
    kolejka *a = new kolejka();
    kolejka *b = new kolejka(17);
    kolejka *c = new kolejka({"a", "b", "c", "d", "e", "f", "g"});
    std::cout<<"Lista [A] = pusta, pojemnosc "<<a->pojemnosc_k()<<"\n";
    std::cout<<"Lista [B] = pusta, pojemnosc "<<b->pojemnosc_k()<<"\n";
    std::cout<<"Lista [C] = "; c->wypisz();
    //kolejka *k = new kolejka(20);
    int opcja; char lista, z_l, do_l;
    std::string napis;
    std::cout<<"    1. Wstaw element.\n";
    std::cout<<"    2. Usun element.\n";
    std::cout<<"    3. Ilosc elementow.\n";
    std::cout<<"    4. Pojemnosc kolejki.\n";
    std::cout<<"    5. Wypisz zawartosc.\n";
    std::cout<<"    6. Wypisz pierwszy element\n";
    std::cout<<"    7. Przenies liste\n";
    std::cout<<"    8. Kopiuj liste\n";
    std::cout<<"    9. Wyjscie.\n";
    while (1) {
        std::cout<<"\n Wybrana opcja: "; std::cin>>opcja;
        if(opcja==9) break;
        switch (opcja) {
            case 1:
                std::cout<<" Podaj liste(A, B, C): "; std::cin>>lista;
                std::cout<<" Podaj element: "; std::cin>>napis;
                try {
                    if(lista=='A') {
                        if(a->pojemnosc_k()==0) {
                            a=new kolejka();
                        }
                        a->wstaw(napis);
                    }
                    else if(lista=='B') {
                        if(b->pojemnosc_k()==0) b=new kolejka();
                        b->wstaw(napis);
                    }
                    else if(lista=='C') {
                        if(c->pojemnosc_k()==0) c=new kolejka();
                        c->wstaw(napis);
                    }
                } catch (std::string msg) {
                    std::cout<<msg<<"\n";
                }
                break;
            case 2:
                std::cout<<" Podaj liste(A, B, C): "; std::cin>>lista;
                try {
                    if(lista=='A') napis = a->pobierz();
                    else if(lista=='B') napis = b->pobierz();
                    else if(lista=='C') napis = c->pobierz();
                    std::cout<<" Usuniety element: "<<napis<<"\n";
                } catch(std::string msg) {
                    std::cout<<msg<<"\n";
                }
                
                break;
            case 3:
                std::cout<<" Podaj liste(A, B, C): "; std::cin>>lista;
                if(lista=='A') std::cout<<" Ilosc elementow: "<<a->rozmiar()<<"\n";
                else if(lista=='B') std::cout<<" Ilosc elementow: "<<b->rozmiar()<<"\n";
                else if(lista=='C') std::cout<<" Ilosc elementow: "<<c->rozmiar()<<"\n";
                break;
        	case 4:
                std::cout<<" Podaj liste(A, B, C): "; std::cin>>lista;
                if(lista=='A') std::cout<<" Pojemnosc: "<<a->pojemnosc_k()<<"\n";
                else if(lista=='B') std::cout<<" Pojemnosc: "<<b->pojemnosc_k()<<"\n";
                else if(lista=='C') std::cout<<" Pojemnosc: "<<c->pojemnosc_k()<<"\n";
                break;
            case 5:
                std::cout<<" Podaj liste(A, B, C): "; std::cin>>lista;
                std::cout<<" Elementy listy ["<<lista<<"]: ";
                if(lista=='A') a->wypisz();
                else if(lista=='B') b->wypisz();
                else if(lista=='C') c->wypisz();
                break;
            case 6:
                std::cout<<" Podaj liste(A, B, C): "; std::cin>>lista;
                if(lista=='A') std::cout<<" Pierwszy element: "<<a->sprawdz()<<"\n";
                else if(lista=='B') std::cout<<" Pierwszy element: "<<b->sprawdz()<<"\n";
                else if(lista=='C') std::cout<<" Pierwszy element: "<<c->sprawdz()<<"\n";
                break;
            case 7:
                std::cout<<"Przenies [_] do [_]: "; std::cin>>z_l>>do_l;
                std::cout<<"Przed przeniesieniem: \n["<<z_l<<"]: ";
                if(z_l=='A') a->wypisz();
                else if(z_l=='B') b->wypisz();
                else if(z_l=='C') c->wypisz();
                std::cout<<"["<<do_l<<"]: ";
                if(do_l=='A') a->wypisz();
                else if(do_l=='B') b->wypisz();
                else if(do_l=='C') c->wypisz();
                
                if(z_l=='A') {
                    if(do_l=='A') *a = std::move(*a);
                    else if(do_l=='B') *b = std::move(*a);
                    else if(do_l=='C') *c = std::move(*a);
                }
                else if(z_l=='B') {
                    if(do_l=='A') *a = std::move(*b);
                    else if(do_l=='B') *b = std::move(*b);
                    else if(do_l=='C') *c = std::move(*b);
                }
                else if(z_l=='C') {
                    if(do_l=='A') *a = std::move(*c);
                    else if(do_l=='B') *b = std::move(*c);
                    else if(do_l=='C') *c = std::move(*c);
                }
                std::cout<<"Po przeniesieniu: \n["<<z_l<<"]: ";
                if(z_l=='A') a->wypisz();
                else if(z_l=='B') b->wypisz();
                else if(z_l=='C') c->wypisz();
                std::cout<<"["<<do_l<<"]: ";
                if(do_l=='A') a->wypisz();
                else if(do_l=='B') b->wypisz();
                else if(do_l=='C') c->wypisz();
                break;
            case 8:
                std::cout<<"Kopiuj [_] do [_]: "; std::cin>>z_l>>do_l;
                std::cout<<"Przed skopiowaniem: \n["<<z_l<<"]: ";
                if(z_l=='A') a->wypisz();
                else if(z_l=='B') b->wypisz();
                else if(z_l=='C') c->wypisz();
                std::cout<<"["<<do_l<<"]: ";
                if(do_l=='A') a->wypisz();
                else if(do_l=='B') b->wypisz();
                else if(do_l=='C') c->wypisz();
                
                if(z_l=='A') {
                    if(do_l=='A') *a = *a;
                    else if(do_l=='B') *b = *a;
                    else if(do_l=='C') *c = *a;
                }
                else if(z_l=='B') {
                    if(do_l=='A') *a = *b;
                    else if(do_l=='B') *b = *b;
                    else if(do_l=='C') *c = *b;
                }
                else if(z_l=='C') {
                    if(do_l=='A') *a = *c;
                    else if(do_l=='B') *b = *c;
                    else if(do_l=='C') *c = *c;
                }
                std::cout<<"Po skopiowaniu: \n["<<z_l<<"]: ";
                if(z_l=='A') a->wypisz();
                else if(z_l=='B') b->wypisz();
                else if(z_l=='C') c->wypisz();
                std::cout<<"["<<do_l<<"]: ";
                if(do_l=='A') a->wypisz();
                else if(do_l=='B') b->wypisz();
                else if(do_l=='C') c->wypisz();
                break;
                
            default:
                std::cout<<" Nieprawidlowa opcja.\n";
        }
    }
    delete a;
    delete b;
    delete c;
    return 0;
}