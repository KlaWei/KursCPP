#include <iostream>
#include <vector>
#include "PlikWejsciowy.hpp"
#include "PlikWyjsciowy.hpp"

using namespace obliczenia;

int main() {
    PlikWejsciowy rein("reals_in.txt");
    PlikWyjsciowy reout("reals_out.txt");
    std::vector<double> liczby;
    try {
        double d;
        while(!rein.end_of_file()) {
            d = rein.get_input<double>();
            liczby.push_back(d);
        }
        for (auto i = liczby.end()-1; i>=liczby.begin();i--) {
            reout<<(*i)<<" ";
        }
    } catch (std::ios_base::failure &e) {
            std::cout<<"\n"<<e.what()<<"\n";
    }
}
