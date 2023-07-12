#include "../inc.h"

class Solution {
   public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 != 0) return {};
        vector<long long> ret;
        for (long long i = 2; i <= finalSum; i += 2) {
            ret.emplace_back(i);
            finalSum -= i;
        }
        ret.back() += finalSum;

        return ret;
    }
};


void test(long long finalSum, vector<long long>&& expect) {
    std::sort(expect.begin(), expect.end());
    Solution so;
    auto ret = so.maximumEvenSplit(finalSum);
    std::sort(ret.begin(), ret.end());
    if (ret == expect) {
        print("ok");
    } else {
        long long sum = 0;
        for_each(ret.begin(), ret.end(), [&](long long val) { sum += val; });
        if (sum == finalSum || ret.size() == expect.size()) {
            print("ok");
        } else {
            print("not ok");
            print(finalSum);
            print(expect);
            print(ret);
            print();
        }
    }
}

int main() {
    test(12, {2, 4, 6});
    test(7, {});
    test(28, {6, 8, 2, 12});
    test(28, {2, 4, 6, 16});
    return 0;
}
