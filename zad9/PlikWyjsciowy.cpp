#include "PlikWyjsciowy.hpp"

namespace obliczenia {

PlikWyjsciowy::PlikWyjsciowy(const char *name) {
    file.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    try {
        file.open(name);
    } catch (std::ios_base::failure &e) {
        std::cout<<e.what()<<"\n";
    }
}

PlikWyjsciowy::~PlikWyjsciowy() {
    try {
        file.close();
    } catch (std::ios_base::failure &e) {
        std::cout<<e.what()<<"\n";
    }
}
}
