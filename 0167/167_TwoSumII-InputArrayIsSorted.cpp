#include "../inc.h"

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {}
};

void test(vector<int>&& numbers, int target, vector<int>&& expect) {
    save4print(numbers);
    save4print(target);
    Solution so;
    auto ret = so.twoSum(numbers, target);
    std::sort(ret.begin(), ret.end());
    std::sort(expect.begin(), expect.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test({2, 7, 11, 15}, 9, {1, 2});
    test({2, 3, 4}, 6, {1, 3});
    test({-1, 0}, -1, {1, 2});
    return 0;
}
