#include "../inc.h"

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> n2count;
        for (int n : nums) ++n2count[n];
        for (auto [n, count] : n2count)
            if (count == 1) return n;
        return - 1;
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().singleNumber(nums));
}

int main() {
    test({2, 2, 3, 2}, 3);
    test({0, 1, 0, 1, 0, 1, 99}, 99);
    return 0;
}
