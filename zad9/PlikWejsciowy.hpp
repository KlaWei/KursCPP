#ifndef PLIK_IN_H
#define PLIK_IN_H

#include <fstream>
#include <iostream>

namespace obliczenia {

class PlikWejsciowy {
    std::ifstream file;
    public:
        PlikWejsciowy(const char *filename);
        ~PlikWejsciowy();
        template <class T>
        T get_input();
        template <typename T>
        friend PlikWejsciowy& operator >> (PlikWejsciowy &in, T &wartosc);
        bool end_of_file() { return file.eof(); }
};

template <class T>
T PlikWejsciowy::get_input() {
    T elem;
    file>>elem;
    return elem;
}

template <typename T>
PlikWejsciowy& operator >> (PlikWejsciowy &in, T &wartosc) {
    in.file >> wartosc;
    return in;
}
}

#endif