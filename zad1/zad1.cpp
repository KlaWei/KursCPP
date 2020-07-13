#include <iostream>
#include <string>

struct Rzymskie {
    int val;
    std::string num;
};

int strlength(const char *x) {
    int i=0;
    while (x[i]!='\0') i++;
    
    return i;
}

int isnum(const char *x) {
    int i=0;
    while (x[i]!='\0') {
        if(x[i]<'0' || x[i]>'9') return 0;
        i++;
    }
    return 1;
}

int arab2bin(const char *x) {
    if(strlength(x)>4) {
        std::cerr<<"Error: Dlugosc "<<x<<" przekracza 4 znaki.\n";
        return 0;
    }
    if(x[0]=='0') {
        std::cerr<<"Error: Napis "<<x<<" rozpoczyna sie od zera.\n";
        return 0;
    }
    if (!isnum(x)) {
        std::cerr<<"Error: Napis "<<x<<" nie jest liczba.\n";
        return 0;
    }
    return std::stoi(x);
    
}

std::string bin2rzym(int x) {
    const Rzymskie rom[]= {
        {1000, "M"}, {900, "CM"}, {500, "D"},
        {400, "CD"}, {100, "C"}, {90, "XC"},
        {50, "L"}, {40, "XL"}, {10, "X"},
        {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}, {0, "0"}};
    std::string wynik;
    const Rzymskie* temp;
    for (temp=rom; temp->val>=1; temp++) {
        while (x>=temp->val) {
            wynik+=temp->num;
            x-=temp->val;
        }
    }
    return wynik;
}

int main(int argc, char *argv[]) {
    if(argc==1) std::cerr<<"Error: Za malo argumentow.\n";
    std::string wynik;
    //std::cout<<"argc = "<<argc<<"\n";
    for (int i=1;i<argc;i++) {
        int x=arab2bin(argv[i]);
        if(x>0) {
            wynik = bin2rzym(x);
            std::cout<<wynik<<"\n";
        }
    }
}

