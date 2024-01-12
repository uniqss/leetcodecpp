#include "../inc.h"

class Solution {
   public:
    int countTestedDevices(vector<int>& batteryPercentages) {}
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
