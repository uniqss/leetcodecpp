#include "../inc.h"

class Solution {
   public:
    int largestAltitude(vector<int>& gain) {}
};

void test(vector<int>&& gain, int expect) {
    auto gain_param = gain;
    Solution so;
    auto ret = so.largestAltitude(gain);
    assert_eq_ret(expect, ret);
    print(gain_param);
}

int main() {
    test({-5, 1, 5, 0, -7}, 1);
    test({-4, -3, -2, -1, 4, 3, 2}, 0);
    return 0;
}