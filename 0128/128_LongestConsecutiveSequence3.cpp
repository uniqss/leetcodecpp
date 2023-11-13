#include "../inc.h"

// 也还凑和吧，比二哈刨的代码强点
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> startingmax, endingmax;
        unordered_set<int> nvalid(nums.begin(), nums.end());
        int ret = 0;
        for (int n : nvalid) {
            int nextmax = startingmax[n + 1];
            int premax = endingmax[n - 1];
            int currmax = premax + nextmax + 1;
            startingmax[n - premax] = currmax;
            endingmax[n + nextmax] = currmax;
            ret = max(ret, currmax);
        }
        return ret;
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    Solution so;
    auto ret = so.longestConsecutive(nums);
    assert_eq_ret(expect, ret);
}

int main() {
    test({-6, 8, -5, 7, -9, -1, -7, -6, -9, -7, 5, 7, -1, -8, -8, -2, 0}, 5);
    test({100, 4, 200, 1, 3, 2}, 4);
    test({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9);
    return 0;
}
