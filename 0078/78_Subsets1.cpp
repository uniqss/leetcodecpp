#include "../inc/inc.h"

/*
首先第一层，长度 [0,n]
其次第二层，backtrace
    首先判定是否已达长度k,达则添加返回
    从当前起始位置first开始依次往后添加一个元素入curr
        backtrace 注意新的first值=i+1(first的意义：当前backtrace中可顺序往后取的第一个元素的下标)
*/
class Solution {
    int n, k;

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        n = nums.size();
        for (k = 0; k <= n; ++k) {
            vector<int> curr;
            backtrace(ret, curr, 0, nums);
        }

        return ret;
    }
    void backtrace(vector<vector<int>>& ret, vector<int>& curr, int first, const vector<int>& nums) {
        if (curr.size() == k) {
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
