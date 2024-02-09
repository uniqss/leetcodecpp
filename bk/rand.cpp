#include "../inc.h"

#include <random>

int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    vector<int> d;
    for (int i = 1; i <= 52; ++i) d.push_back(((i - 1) % 13) + 1);
    d.push_back(14);
    d.push_back(15);
    std::uniform_int_distribution<int> dist(0, (int)d.size() - 1);

    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << d[dist(mt)] << "\t";
        }
        cout << endl;
    }
    return 0;
}