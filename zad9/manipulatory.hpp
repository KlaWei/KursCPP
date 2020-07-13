#ifndef MANIPULATORY_H
#define MANIPULATORY_H

#include <iostream>
#include <string>

namespace obliczenia {

// bezparametrowy
inline std::istream& clearline (std::istream &is) {
    char c;
    while (!is.eof() && c!='\n') { c=is.get(); }
    return is;
}

inline std::ostream& comma (std::ostream &os) {
    os<<", ";
    return os;
}

inline std::ostream& colon (std::ostream &os) {
    os<<": ";
    return os;
}

class ignore {
    int x;
    friend std::istream& operator >> (std::istream &is, const ignore &ig) {
        int i;
        char c;
        for (i=0;i<ig.x && !is.eof() && c!='\n';i++) {
            c=is.get();
        }
        return is;
    }
    public:
        ignore(int ilosc) : x(ilosc) {}
};

class index1 {
    int x, w;
    public:
        friend std::ostream& operator << (std::ostream &os, const index1 &ind) {
            os<<"[";
            std::string str = std::to_string(ind.x);
            if((ind.w-2-(int)str.length())>0) {
                for (int i = 0;i<(ind.w-2-(int)str.length());i++) {
                    os<<" ";
                }
            }
            os<<ind.x<<"]";
            return os;
        }
        index1(int liczba, int ilosc) : x(liczba), w(ilosc) {} 
};
}

#endif