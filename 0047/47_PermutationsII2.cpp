#include "../inc.h"

/*
这个方法的空间复杂度不错，但是时间复杂度非常差，没有做剪枝
*/
namespace std {
template <>
struct hash<vector<int>> {
    size_t operator()(const vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            // seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            // to make things simpler
            seed ^= hasher(i);
        }
        return seed;
    };
};
}  // namespace std

class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_set<vector<int>> dict;
        vector<vector<int>> ret;
        dfs(dict, nums, 0, nums.size());
        ret.insert(ret.end(), dict.begin(), dict.end());
        return ret;
    }
    void dfs(unordered_set<vector<int>>& ret, vector<int>& nums, int start, int len) {
        if (start == len) {
            ret.insert(nums);
            return;
        }
        for (int i = start; i < len; ++i) {
            swap(nums[start], nums[i]);
            dfs(ret, nums, start + 1, len);
            swap(nums[start], nums[i]);
        }
    }
};

void test(vector<int>&& nums, vector<vector<int>>&& expect) {
    save4print(nums);
    auto ret = Solution().permuteUnique(nums);
    std::sort(expect.begin(), expect.end());
    std::sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test({1, 1, 2}, {{1, 1, 2}, {1, 2, 1}, {2, 1, 1}});
    test({1, 2, 3}, {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}});
    test({0, 1}, {{0, 1}, {1, 0}});
    test({1}, {{1}});
    return 0;
}
