#include "kolejka.hpp"

int main() {
    kolejka *k = new kolejka(6);
    int opcja;
    std::string napis;
    std::cout<<"    1. Wstaw element.\n";
    std::cout<<"    2. Usun element.\n";
    std::cout<<"    3. Ilosc elementow.\n";
    std::cout<<"    4. Pojemnosc kolejki.\n";
    std::cout<<"    5. Wypisz zawartosc.\n";
    std::cout<<"    6. Wypisz pierwszy element\n";
    std::cout<<"    7. Wyjscie.\n";
    while (1) {
        std::cout<<"\n Wybrana opcja: "; std::cin>>opcja;
        if(opcja==7) break;
        switch (opcja) {
            case 1:
                std::cout<<" Podaj element: "; std::cin>>napis;
                try {
                    k->wstaw(napis);
                } catch(std::string msg) {
                    std::cout<<msg<<"\n";
                }
                break;
            case 2:
                try {
                    napis = k->pobierz();
                    std::cout<<" Usuniety element: "<<napis<<"\n";
                } catch(std::string msg) {
                    std::cout<<msg<<"\n";
                }
                
                break;
            case 3:
                std::cout<<" Ilosc elementow: "<<k->rozmiar()<<"\n";
                break;
        	case 4:
                std::cout<<" Pojemnosc: "<<k->pojemnosc_k()<<"\n";
                break;
            case 5:
                std::cout<<" Elementy: ";
                k->wypisz();
                break;
            case 6:
                std::cout<<" Pierwszy element: "<<k->sprawdz()<<"\n";
                break;
            default:
                std::cout<<" Nieprawidlowa opcja.\n";
        }
    }
    
    return 0;
}
