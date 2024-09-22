#include "../inc.h"

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> dict;
        for (auto num : nums) {
            if (dict.count(num) > 0) return true;
            dict.insert(num);
        }
        return false;
    }
};

void test(vector<int>&& nums, bool expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().containsDuplicate(nums));
}

int main() {
    test({1, 2, 3, 1}, true);
    test({1, 2, 3, 4}, false);
    test({1, 1, 1, 3, 3, 4, 3, 2, 4, 2}, true);
    return 0;
}
