#include "../inc.h"

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {}
};

void test(vector<int>&& tempratures, vector<int>&& expect) {
    auto p1 = tempratures;
    Solution so;
    auto ret = so.dailyTemperatures(tempratures);
    assert_eq_ret(expect, ret);
    print(p1);
}

int main() {
    test({73, 74, 75, 71, 69, 72, 76, 73}, {1, 1, 4, 2, 1, 1, 0, 0});
    test({30, 40, 50, 60}, {1, 1, 1, 0});
    test({30, 60, 90}, {1, 1, 0});
    return 0;
}
