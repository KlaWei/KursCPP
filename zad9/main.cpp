#include <iostream>
#include <vector>
#include <algorithm>
#include "manipulatory.hpp"

using namespace obliczenia;

bool my_compare(std::pair<int, std::string> a, std::pair<int, std::string> b) {
    return a.second < b.second;
}

int main() {
    std::vector<std::pair<int, std::string>> lines;
    std::string line;
    int i = 1;
    while (std::getline(std::cin, line)) {
        lines.push_back(std::make_pair(i, line));
        i++;
    }
    
    std::sort(lines.begin(), lines.end(), my_compare);
    
    for (auto a = lines.begin();a!=lines.end();a++) {
        std::cout<<index1((*a).first, 0)<<colon<<(*a).second<<comma<<'\n';
    }
    
}