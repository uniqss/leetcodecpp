#include "../inc.h"

#include <random>

void rd(vector<int>& d) {
    if (d.empty()) return;
    int dsize = d.size();
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, dsize - 1);

    for (int i = 0; i < d.size(); ++i) {
        swap(d[i], d[dist(mt)]);
    }
}

int main() {
    vector<int> d;
    for (int i = 1; i <= 52; ++i) d.push_back(((i - 1) % 13) + 1);
    d.push_back(14);
    d.push_back(15);

    rd(d);
    rd(d);
    rd(d);

    for (int i = 0, j = 0; i < d.size(); ++i) {
        std::cout << d[i] << "\t";
        if (++j % 4 == 0) cout << endl;
    }
    return 0;
}