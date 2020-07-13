#include "wielomian.hpp"

int main() {
    const double t[]={1,2,3,6};
    
    try {
        wielomian a;
        std::cin>>a;
        wielomian b(3, t);
        wielomian c({2.3,8.9,-10,12,1,3,5.3});
        std::cout<<"a: "<<a<<"\n";
        std::cout<<"b: "<<b<<"\n";
        std::cout<<"c: "<<c<<"\n";
        wielomian d=a*b;
        std::cout<<"d=[a*b]: "<<d<<", stopien="<<d.stopien()<<"\n";
        std::cout<<"wartosc a w punkcie 1"<<a(1)<<"\n";
        //std::cout<<"a: "<<a<<"\n";
        a*=2;
        std::cout<<"a*2: "<<a<<"\n";
        wielomian e=c+b;
        std::cout<<"e=[c+b]: "<<e<<"\n";
        c-=b;
        std::cout<<"c=[c-b]: "<<c<<"\n";
        
        std::cout<<"\nPrzypisania i kopie\n";
        a=b;
        std::cout<<"[a=b], a: "<<a<<"\n";
        std::cout<<"b: "<<b<<"\n";
        
        b=std::move(c);
        std::cout<<"[b=move(c)], b: "<<b<<", stopien="<<b.stopien()<<"\n";
        std::cout<<"c: "<<c<<", stopien="<<c.stopien()<<"\n";
        
        
    } catch(std::invalid_argument exc) {
        std::cerr<<exc.what()<<"\n";
    }
    //std::cout<<w;
}