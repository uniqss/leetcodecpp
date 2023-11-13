#include "../inc.h"

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> dict;
        for (int num : nums) {
            ++dict[num];
        }
        for (auto it : dict) {
            if (it.second == 1) return it.first;
        }
        return 0;
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().singleNumber(nums));
}

int main() {
    test({2, 2, 1}, 1);
    test({4, 1, 2, 1, 2}, 4);
    test({1}, 1);
    return 0;
}
