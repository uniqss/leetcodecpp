#include "../inc.h"

/* 这个算法简直太特么经典了，叹为观止，完美的还原了我们整个搜索的过程：
        先从剩下的数里面挨个找一个
            再将它和第一个换一下
                再从下一个位置递归
            再将前面换的换回来
*/
class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        dfs(ret, nums, 0, nums.size());
        return ret;
    }
    void dfs(vector<vector<int>>& ret, vector<int>& nums, int start, int len) {
        if (start == len) {
            ret.emplace_back(nums);
            return;
        }
        for (int i = start; i < len; ++i) {
            std::swap(nums[i], nums[start]);
            dfs(ret, nums, start + 1, len);
            std::swap(nums[i], nums[start]);
        }
    }
};

void test(vector<int>&& nums, vector<vector<int>>&& expect) {
    Solution so;
    auto ret = so.permute(nums);

    auto _sort = [](vector<vector<int>>& vvi) {
        std::sort(vvi.begin(), vvi.end()), [](const vector<int>& lhs, const vector<int>& rhs) {
            size_t len = std::min(lhs.size(), rhs.size());
            for (size_t i = 0; i < len; ++i) {
                if (lhs[i] < rhs[i]) return true;
            }
            return false;
        };
    };
    _sort(expect);
    _sort(ret);

    if (ret == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        pvraw(nums);
        pvvraw(expect);
        pvvraw(ret);
    }
}

int main() {
    test({5, 4, 6, 2}, {{5, 4, 6, 2}, {5, 4, 2, 6}, {5, 6, 4, 2}, {5, 6, 2, 4}, {5, 2, 4, 6}, {5, 2, 6, 4}, {4, 5, 6, 2}, {4, 5, 2, 6},
                        {4, 6, 5, 2}, {4, 6, 2, 5}, {4, 2, 5, 6}, {4, 2, 6, 5}, {6, 5, 4, 2}, {6, 5, 2, 4}, {6, 4, 5, 2}, {6, 4, 2, 5},
                        {6, 2, 5, 4}, {6, 2, 4, 5}, {2, 5, 4, 6}, {2, 5, 6, 4}, {2, 4, 5, 6}, {2, 4, 6, 5}, {2, 6, 5, 4}, {2, 6, 4, 5}});
    test({1, 2, 3}, {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}});
    test({0, 1}, {{0, 1}, {1, 0}});
    test({1}, {{1}});
    return 0;
}

/*
[1,2,3]
[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
[0,1]
[[0,1],[1,0]]
[1]
[[1]]
[1,2,3,4]
[
[1,2,3,4],[1,2,4,3],[1,3,2,4],[1,3,4,2],[1,4,2,3],[1,4,3,2],
[2,1,3,4],[2,1,4,3],[2,3,1,4],[2,3,4,1],[2,4,1,3],[2,4,3,1],
[3,1,2,4],[3,1,4,2],[3,2,1,4],[3,2,4,1],[3,4,1,2],[3,4,2,1],
[4,1,2,3],[4,1,3,2],[4,2,1,3],[4,2,3,1],[4,3,1,2],[4,3,2,1]]
*/
