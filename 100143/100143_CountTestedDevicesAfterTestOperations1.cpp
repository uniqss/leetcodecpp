#include "../inc.h"

// 这是当时临场发挥的，其实是可以简化直接O(n)过的
class Solution {
   public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ret = 0, n = batteryPercentages.size();
        for (int i = 0; i < n; ++i) {
            if (batteryPercentages[i] > 0) {
                ++ret;
                for (int j = i + 1; j < n; ++j) --batteryPercentages[j];
            }
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
