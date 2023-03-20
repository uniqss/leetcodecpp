#include "../inc/inc.h"

/*
把中文官方解法稍微整理了一下，对比11解法，感觉11更容易理解，锁定长度两层for，思路很清晰

理解： [3, 5, 8]  三个数字，对于某一位3、5、8中的任何一个而言，都有两种状态：被选中，不被选中
这么一想就好理解了，选中当前，不选中当前

                3o                              3x
        5o              5x              5o              5x
    8o      8x      8o      8x      8o      8x      8o      8x

这样一画就明白了，就是一棵完全二叉树

*/
class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> temp;
        dfs(ret, temp, 0, nums);
        return ret;
    }
    void dfs(vector<vector<int>>& ret, vector<int>& temp, int curr, const vector<int>& nums) {
        if (curr == nums.size()) {
            ret.emplace_back(temp);
            return;
        }
        // 选中curr位的数字后
        temp.push_back(nums[curr]);
        // 递归再看下一位
        dfs(ret, temp, curr + 1, nums);
        temp.pop_back();
        // 不选中curr位置后，递归看下一位
        dfs(ret, temp, curr + 1, nums);
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
