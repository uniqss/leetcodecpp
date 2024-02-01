#include "../inc.h"

class Solution {
   public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);
        set<int> dict;
        vector<int> sufcount(n+1, 0);
        for (int i = n - 1; i >= 0; --i) {
            dict.insert(nums[i]);
            sufcount[i] = dict.size();
        }
        dict.clear();
        for (int i = 0; i < n; ++i) {
            dict.insert(nums[i]);
            ret[i] = dict.size() - sufcount[i+1];
        }
        return ret;
    }
};


void test(vector<int>&& nums, const vector<int>& expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().distinctDifferenceArray(nums));
}
int main() {
    test({1, 2, 3, 4, 5}, {-3, -1, 1, 3, 5});
    test({3, 2, 3, 4, 2}, {-2, -1, 0, 2, 3});
    return 0;
}