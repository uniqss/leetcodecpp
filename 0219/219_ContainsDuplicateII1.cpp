#include "../inc.h"

class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> dict;
        for (int i = 0; i < nums.size(); i++) {
            if (dict.count(nums[i]) > 0) return true;
            dict.insert(nums[i]);
            if (i >= k) dict.erase(nums[i - k]);
        }
        return false;
    }
};

void test(vector<int>&& nums, int k, bool expect) {
    save4print(nums);
    save4print(k);
    Solution so;
    auto ret = so.containsNearbyDuplicate(nums, k);
    assert_eq_ret(expect, ret);
}

int main() {
    test({1, 2, 3, 1}, 3, true);
    test({1, 0, 1, 1}, 1, true);
    test({1, 2, 3, 1, 2, 3}, 2, false);
    return 0;
}
