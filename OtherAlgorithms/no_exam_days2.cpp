#include <vector>
#include <algorithm>
#include <limits.h>
#include <iostream>
#include <unordered_set>
using namespace std;

int no_exam_days2(vector<int>& an, int t) {
    int ret = 0;

    sort(an.begin(), an.end());

    vector<int> prime1000;
    for (int i = 2; i < 1000 && i <= t; ++i) {
        bool is_prime = true;
        for (auto p : prime1000) {
            if (i % p == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) prime1000.push_back(i);
    }

    unordered_set<int> prime_existed;

    vector<int> an_fixed;
    for (int ai : an) {
        bool valid = true;
        for (int fixed : an_fixed) {
            if (ai % fixed == 0) {
                valid = false;
                break;
            }
        }
        if (valid) {
            an_fixed.push_back(ai);
            for (int p : prime1000) {
                if (p > ai) break;
                if (ai % p == 0) prime_existed.insert(p);
            }
        }
    }

    int arange = 1;
    for_each(prime_existed.begin(), prime_existed.end(), [&](int ai) { arange *= ai; });

    int repeate_count = 0;
    if (t > arange) {
        repeate_count += (t / arange);
    }
    t %= arange;

    int range_no_exam_count = 0;
    int tail_no_exam_count = 0;

    unordered_set<int> an_existed(an.begin(), an.end());
    for (int i = 1; i <= arange; ++i) {
        if (an_existed.count(i) != 0) continue;

        bool valid = true;
        for (int existed : an_existed) {
            if (i % existed == 0) {
                valid = false;
                break;
            }
        }

        if (valid) {
            ++range_no_exam_count;
            if (i <= t) ++tail_no_exam_count;
        }
    }

    ret = range_no_exam_count * repeate_count + tail_no_exam_count;

    return ret;
}

void test(vector<int>&& an, int t, int expect) {
    auto ret = no_exam_days2(an, t);
    if (ret == expect) {
        cout << "ok" << endl;
    } else {
        cout << "not ok." << endl;
        for_each(an.begin(), an.end(), [](int ai) { cout << ai << "\t"; });
        cout << endl;
        cout << t << endl;
        cout << expect << endl;
        cout << ret << endl;
        cout << "##############################" << endl;
    }
}

int main() {
    test({2, 3}, 4, 1);
    test({2, 3}, 8, 3);
    test({2, 3, 6}, 8, 3);
    test({2, 3, 6}, 4, 1);
    return 0;
}
