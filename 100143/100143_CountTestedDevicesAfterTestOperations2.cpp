#include "../inc.h"

class Solution {
   public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ret = 0, n = batteryPercentages.size(), curr = 0;
        for (int i = 0; i < n; ++i) {
            if (batteryPercentages[i] > curr) ++ret, ++curr;
        }
        return ret;
    }
};

void test(vector<int>&& batteryPercentages, int expect) {
    save4print(batteryPercentages);
    assert_eq_ret(expect, Solution().countTestedDevices(batteryPercentages));
}

int main() {
    test({1, 1, 2, 1, 3}, 3);
    test({0, 1, 2}, 2);
    return 0;
}
