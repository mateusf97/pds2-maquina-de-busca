#include <iostream>

#include <cmath>

#include <string>
#include <vector>
#include <map>

typedef std::map<std::string, std::vector<std::pair<int, int>>> indInv;

int nx(indInv& ind, std::string palavra) {
    int nx = 0;
    for (auto p : ind[palavra])
        if (p.second != 0)
            nx++;

    return nx;
}

float idf(int N, int nx) {
    return log((float) N / nx);
}

float tf(indInv& ind, int arq, std::string palavra) {
    return ind[palavra][arq].second;
}

float W(indInv& ind, int arq, std::string palavra) {
    return tf(ind, arq, palavra) * idf(ind[palavra].size(), nx(ind, palavra));
}

int main() {
    indInv ind;
    ind["A"] = {{0, 3}, {1, 2}, {2, 2}, {3, 0}};
    ind["B"] = {{0, 1}, {1, 0}, {2, 0}, {3, 2}};
    ind["C"] = {{0, 0}, {1, 1}, {2, 0}, {3, 0}};

    std::cout << idf(ind["A"].size(), nx(ind, "A"));
    std::cout << tf(ind, 0, "A") << std::endl;
    std::cout << W(ind, 0, "A") << std::endl;

    return 0;
}