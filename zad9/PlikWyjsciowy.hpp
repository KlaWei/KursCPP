#ifndef PLIK_OUT_H
#define PLIK_OUT_H

#include <fstream>
#include <iostream>

namespace obliczenia {

class PlikWyjsciowy {
    std::ofstream file;
    public:
        PlikWyjsciowy(const char *name);
        ~PlikWyjsciowy();
        template<class T>
        void write_to_file(T el);
        
        template<typename T>
        friend PlikWyjsciowy& operator << (PlikWyjsciowy &out, const T &elem);
};

template<class T>
void PlikWyjsciowy::write_to_file(T el) {
    file<<el;
}

template<typename T>
PlikWyjsciowy& operator << (PlikWyjsciowy &out, const T &elem) {
    out.file << elem;
    return out;
}

}

#endif