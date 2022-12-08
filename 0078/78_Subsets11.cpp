#include "../inc.h"

/*
稍微优化一下，注意长度的范围是[0,n]双闭区间
*/
class Solution {
    int n, len;

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        n = nums.size();
        for (len = 0; len <= n; ++len) {
            vector<int> curr;
            backtrace(ret, curr, 0, nums);
        }

        return ret;
    }
    void backtrace(vector<vector<int>>& ret, vector<int>& curr, int first, const vector<int>& nums) {
        if (curr.size() == len) {
            ret.emplace_back(curr);
            return;
        }

        for (int i = first; i < n; ++i) {
            curr.emplace_back(nums[i]);
            backtrace(ret, curr, i + 1, nums);
            curr.pop_back();
        }
    }
};

void test(vector<int>&& nums, vector<vector<int>>&& expect) {
    Solution so;
    auto ret = so.subsets(nums);
    std::sort(ret.begin(), ret.end());
    std::sort(expect.begin(), expect.end());
    if (expect == ret) {
        print("ok.");
    } else {
        print("not ok.");
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({1, 2, 3}, {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}});
    test({0}, {{}, {0}});
}
