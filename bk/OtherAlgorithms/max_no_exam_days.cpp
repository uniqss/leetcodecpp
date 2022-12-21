#include <vector>
#include <algorithm>
#include <limits.h>
#include <iostream>
using namespace std;

int max_no_exam_days(const vector<int>& an, int t) {
    int ret = INT_MAX;

    std::for_each(an.begin(), an.end(), [&](int ai) { ret = min(ret, ai); });

    ret = min(t, ret);

    return ret;
}

void test(const vector<int>&& an, int t, int expect) {
    auto ret = max_no_exam_days(an, t);
    if (ret == expect) {
        cout << "ok" << endl;
    } else {
        cout << "not ok." << endl;
        for_each(an.begin(), an.end(), [](int ai) { cout << ai << "\t"; });
        cout << endl;
        cout << expect << endl;
        cout << ret << endl;
        cout << "##############################" << endl;
    }
}

int main() {
    test({3, 5, 7, 8}, 4, 3);
    test({3, 5, 7, 8}, 2, 2);
    return 0;
}
