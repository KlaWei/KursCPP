#include "PlikWejsciowy.hpp"

namespace obliczenia {

PlikWejsciowy::~PlikWejsciowy() {
    try {
        file.close();
    } catch (std::ios_base::failure &e) {
        std::cout<<e.what()<<"\n";
    }
}

PlikWejsciowy::PlikWejsciowy(const char *filename) {
    file.exceptions(std::ios_base::badbit | std::ios_base::failbit);
    try {
        file.open(filename);
    } catch (std::ios_base::failure &e) {
        std::cout<<e.what()<<"\n";
    }
}

template <>
std::string PlikWejsciowy::get_input<std::string>() {
    std::string str;
    std::getline(file, str);
    return str;
}
}
