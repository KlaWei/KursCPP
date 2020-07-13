#include "globalne.hpp"

void wypisz_trojkat(trojkat t) {
    std::cout<<"T A("<<t.A().X()<<", "<<t.A().Y()<<"), B("<<t.B().X()<<", "<<
    t.B().Y()<<"), C("<<t.C().X()<<", "<<t.C().Y()<<")\n";
}

void wypisz_punkt(punkt p) {
    std::cout<<"P("<<p.X()<<", "<<p.Y()<<")\n";
}

void wypisz_odcinek(odcinek odc) {
    std::cout<<"A("<<odc.A().X()<<", "<<odc.A().Y()<<"), B("<<odc.B().X()<<", "<<
    odc.B().Y()<<")\n";
}

int main() {
    // punkt
    
    punkt a;
    wypisz_punkt(a); // konstr. domyślny
    a=punkt(5, 7);
    a.obrot(punkt(3,2), 45);
    punkt b=a; // konstr. kopiujący
    wypisz_punkt(b);
    a=punkt(0, 1);
    a.obrot(punkt(0,0), 90);
    wypisz_punkt(a);
    std::cout<<"odleglosc: "<<odleglosc_pkt(a, b)<<"\n";
    std::cout<<"\n";
    // odcinek
    odcinek odc, odc2;
    wypisz_odcinek(odc);
    try {
        odc=odcinek(punkt(0,0), punkt(0, 0));
    } catch (std::string msg) {
        std::cerr<<msg<<std::endl;
    }
    
    punkt p;
    odc=odcinek(punkt(0,0), punkt(4,6));
    odc2=odcinek(punkt(4,2), punkt(0,4));
    try {
        p=pkt_przeciecia(odc, odc);
    } catch (std::string msg) {
        std::cerr<<msg<<std::endl;
    }
    try {
        p=pkt_przeciecia(odc, odc2);
        std::cout<<"punkt przeciecia: ";
        wypisz_punkt(p);
    } catch (std::string msg) {
        std::cerr<<msg<<std::endl;
    }
    std::cout<<odc.dlugosc()<<"\n";
    p=odc.srodek();
    std::cout<<"srodek: ";
    wypisz_punkt(p);
    odcinek odc3=odc;
    odc3.translacja(2, 1);
    wypisz_odcinek(odc3);
    if(odcinki_rownolegle(odc, odc3)) {
        
        std::cout<<"Rownolegle: \n";
        std::cout<<"  "; wypisz_odcinek(odc);
        std::cout<<"  "; wypisz_odcinek(odc3);
    }
    else {
        std::cout<<"Nie rownolegle: \n";
        std::cout<<"  "; wypisz_odcinek(odc);
        std::cout<<"  "; wypisz_odcinek(odc3);
    }
    odc3.obrot(punkt(0,0), 90);
    if(odcinki_prostopadle(odc, odc3)) {
        
        std::cout<<"Prostopadle: \n";
        std::cout<<"  "; wypisz_odcinek(odc);
        std::cout<<"  "; wypisz_odcinek(odc3);
    }
    else {
        std::cout<<"Nie prostopadle: \n";
        std::cout<<"  "; wypisz_odcinek(odc);
        std::cout<<"  "; wypisz_odcinek(odc3);
    }
    
    // trojkat
    trojkat t, t2;
    a=punkt(1.2,3.7);
    try {
        t = trojkat(punkt(1,1), punkt(3,4), punkt(1,4));
        wypisz_trojkat(t);
        std::cout<<"  pole: "<<t.pole()<<", obwod: "<<t.obwod()<<"\n";
        //t.translacja(6, 9);
        bool nalezy = wew_trojkata(a, t);
        if(nalezy) std::cout<<"nalezy";
        //wypisz_trojkat(t);
    } catch(std::string msg) {
        std::cerr<<msg<<std::endl;
    }
    try {
        t2 = trojkat(punkt(0,0), punkt(9,0), punkt(1,7));
        wypisz_trojkat(t2);
    } catch (std::string msg) {
        std::cerr<<msg<<std::endl;
    }
    
    if(zawieranie_trojkatow(t, t2)) std::cout<<"Zawieraja sie\n";
    else std::cout<<"Nie zawieraja sie\n";
    
    if(zawieranie_trojkatow(t, t)) std::cout<<"Zawieraja sie\n";
    else std::cout<<"Nie zawieraja sie\n";
    //trojkat t3, t4;
    
    t2.translacja(0, 2);
    wypisz_trojkat(t2);
    std::cout<<"-----\n";
    bool nalezy = wew_trojkata(punkt(1,1), t2);
    if(nalezy) std::cout<<"nalezy";
    
    if(zawieranie_trojkatow(t, t2)) std::cout<<"Zawieraja sie\n";
    else std::cout<<"Nie zawieraja sie\n";
    
    if(trojkaty_rozlaczne(t, t2)) std::cout<<"Rozlaczne\n";
    else std::cout<<"Nie rozlaczne\n";
    wypisz_trojkat(t2);
    p = t2.srodek();
    std::cout<<"   srodek: "; wypisz_punkt(p);
    std::cout<<" ------\n";
    trojkat t4 = trojkat(punkt(0,0), punkt(3,0), punkt(0,2));
    wypisz_trojkat(t4);
    std::cout<<"   obwod "<<t4.obwod()<<"\n"; // powinno byc 8,60555
    std::cout<<"   pole "<<t4.pole()<<"\n"; // 3
    
}
