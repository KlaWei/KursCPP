#include "wymierna.hpp"

using namespace obliczenia;

int main() {
    try {
        wymierna w(-7,3);
        wymierna w2(-3, 4);
        w=w-w2;
        std::cout<<w<<", "<<w2<<", "<<w<<"\n";
        
        wymierna w4 = ! w;
        std::cout<<"w = "<<w.licznik()<<"/"<<w.mianownik()<<" !w: "<<w4.licznik()<<"/"<<w4.mianownik()<<"\n";
        std::cout<<"w4="<<w4<<"\n";
        
        wymierna w5(1345, 36);
        std::cout<<w5.licznik()<<"/"<<w5.mianownik()<<" "<<(int)w5<<"\n";
        
        std::cout<<"Opcje:\n";
        int opcja, l1, l2, m1, m2;
        std::cout<<"1. Dodaj\n"<<"2. Odejmnij\n"<<"3. Pomnoz\n"<<"4. Podziel\n"<<"5. Odwroc\n"<<"6. Wyjscie\n";
        while (1) {
            std::cout<<"Opcja: ";
            std::cin>>opcja;
            if(opcja==6) break;
            switch (opcja) {
                case 1: {
                    std::cout<<"Pierwsza liczba(l, m): ";
                    std::cin>>l1>>m1;
                    wymierna wym1(l1, m1);
                    std::cout<<"Druga liczba(l, m): ";
                    std::cin>>l2>>m2;
                    wymierna wym2(l2, m2);
                    std::cout<<"a("<<wym1.licznik()<<"/"<<wym1.mianownik()<<") + b("<<wym2.licznik()<<"/"<<wym2.mianownik()<<") = ";
                    wymierna c = wym1+wym2;
                    std::cout<<"c("<<c.licznik()<<"/"<<c.mianownik()<<") = "<<c<<"\n";
                    break;
                }
                case 2: {
                    std::cout<<"Pierwsza liczba(l, m): ";
                    std::cin>>l1>>m1;
                    wymierna wym1(l1, m1);
                    std::cout<<"Druga liczba(l, m): ";
                    std::cin>>l2>>m2;
                    wymierna wym2(l2, m2);
                    std::cout<<"a("<<wym1.licznik()<<"/"<<wym1.mianownik()<<") - b("<<wym2.licznik()<<"/"<<wym2.mianownik()<<") = ";
                    wymierna c = wym1-wym2;
                    std::cout<<"c("<<c.licznik()<<"/"<<c.mianownik()<<") = "<<c<<"\n";
                    break;
                }
                case 3: {
                    std::cout<<"Pierwsza liczba(l, m): ";
                    std::cin>>l1>>m1;
                    wymierna wym1(l1, m1);
                    std::cout<<"Druga liczba(l, m): ";
                    std::cin>>l2>>m2;
                    wymierna wym2(l2, m2);
                    std::cout<<"a("<<wym1.licznik()<<"/"<<wym1.mianownik()<<") * b("<<wym2.licznik()<<"/"<<wym2.mianownik()<<") = ";
                    wymierna c = wym1*wym2;
                    std::cout<<"c("<<c.licznik()<<"/"<<c.mianownik()<<") = "<<c<<"\n";
                    break;
                }
                case 4: {
                    std::cout<<"Pierwsza liczba(l, m): ";
                    std::cin>>l1>>m1;
                    wymierna wym1(l1, m1);
                    std::cout<<"Druga liczba(l, m): ";
                    std::cin>>l2>>m2;
                    wymierna wym2(l2, m2);
                    std::cout<<"a("<<wym1.licznik()<<"/"<<wym1.mianownik()<<") / b("<<wym2.licznik()<<"/"<<wym2.mianownik()<<") = ";
                    wymierna c = wym1/wym2;
                    std::cout<<"c("<<c.licznik()<<"/"<<c.mianownik()<<") = "<<c<<"\n";
                    break;
                }
                case 5: {
                    std::cout<<"Liczba(l,m): ";
                    std::cin>>l1>>m1;
                    wymierna wym(l1, m1);
                    wymierna c = !wym;
                    std::cout<<"a = "<<wym.licznik()<<"/"<<wym.mianownik()<<"\n";
                    std::cout<<"!a = "<<c.licznik()<<"/"<<c.mianownik()<<"\n";
                    break;
                }
            }
        }
        
    } catch (dzielenie_przez_0 e) {
        std::cout<<"\nBLAD: "<<e.what()<<"\n";
    }
    catch (przekroczenie_zakresu e) {
        std::cout<<"\nBLAD: "<<e.what()<<"\n";
    }
}