#include "../../inc.h"

int main() {
    vector<pair<int, int>> vii;
    vii.push_back({1, 100});
    vii.push_back({1, 200});
    vii.push_back({10, 37});
    vii.push_back({10, 30});
    vii.push_back({2, 37});
    vii.push_back({9, 37});
    vii.push_back({3, 37});
    vii.push_back({8, 37});
    vii.push_back({4, 37});
    vii.push_back({6, 37});
    vii.push_back({5, 37});
    std::sort(vii.begin(), vii.end(), [](const auto& lhs, const auto& rhs) { return lhs.first < rhs.first; });
    vector<ComplexVal> vr;
    for (auto it : vii) {
        vr.push_back(it);
    }

    print(vr);
    return 0;
}
