#include <iostream>
#include "bst.hpp"

int main() {
    bst<int> *drzewo = new bst<int>();
    drzewo->wstaw(3);
    drzewo->wstaw(5);
    drzewo->wstaw(1);
    drzewo->wstaw(4);
    drzewo->wstaw(2);
    drzewo->wstaw(0);
    bst<int> drzewo2;
    drzewo2 = *drzewo;
    std::cout<<*drzewo;
    drzewo->usun(3);
    drzewo->usun(5);
    bst<int> drzewo3(*drzewo);
    drzewo->usun(0);
    //bst<int> drzewo4({1,2,6,7,9,12});
    //bst<int> drzewo5({1,2,6,7,9,12});
    bst<int> *Drzewo = new bst<int>();
    //std::cout<<"drzewo: "<<*drzewo;
    std::cout<<"drzewo 2: "<<drzewo2;
    std::cout<<"drzewo 3: "<<drzewo3;
    //std::cout<<"drzewo 4: "<<drzewo4;
    std::cout<<"1. Wstaw do drzewa\n2. Usun z drzewa\n3. Wyswietl\n4. Szukaj\n5. Wyjscie\n";
    int opcja, el;
    
    
    
    while(1) {
        std::cout<<"Opcja: ";
        std::cin>>opcja;
        if(opcja==5) break;
        switch(opcja) {
            case 1: 
                std::cout<<"Podaj element(int): ";
                std::cin>>el;
                Drzewo->wstaw(el);
                break;
            case 2:
                std::cout<<"Podaj element: ";
                std::cin>>el;
                Drzewo->usun(el);
                break;
            case 3:
                std::cout<<"drzewo: "<<*Drzewo;
                break;
            case 4:
                std::cout<<"Podaj element: ";
                std::cin>>el;
                if(Drzewo->szukaj(el)) std::cout<<"Element jest w drzewie\n";
                else std::cout<<"Elementu nie ma w drzewie\n";
                break;
        }
    }
    delete Drzewo;
    delete drzewo;
}


