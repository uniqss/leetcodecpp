#include "../inc.h"

class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        for (size_t i = 0; i < nums.size(); i++) {
            auto it = dict.find(nums[i]);
            if (it != dict.end()) {
                if (i - it->second <= k) return true;
            }
            dict[nums[i]] = i;
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
