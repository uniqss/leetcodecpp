#include "../stl.h"

class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());
        ret.emplace_back(nums);

        size_t nsize = nums.size();
        while (true) {
            int pos = -1;
            for (size_t i = nsize - 1; i > 0; --i) {
                if (nums[i] > nums[i - 1]) {
                    pos = i - 1;
                    break;
                }
            }
            if (pos == -1) break;
            int right_pos = -1;
            int right_val = INT_MAX;
            for (size_t i = nsize - 1; i > pos; --i) {
                if (nums[i] > nums[pos] && nums[i] < right_val) {
                    right_val = nums[i];
                    right_pos = i;
                }
            }
            swap(nums[pos], nums[right_pos]);
            if (pos < nsize - 2) sort(nums.begin() + pos + 1, nums.end());
            ret.emplace_back(nums);
        }

        return ret;
    }
};

void test(vector<int>&& nums, vector<vector<int>>&& expect) {
    Solution so;
    auto ret = so.permuteUnique(nums);
    std::for_each(expect.begin(), expect.end(), [](auto& v) { std::sort(v.begin(), v.end()); });
    std::sort(expect.begin(), expect.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
        for (size_t i = 0; i < lhs.size(); ++i) {
            if (lhs[i] < rhs[i]) return true;
        }
        return false;
    });
    std::for_each(ret.begin(), ret.end(), [](vector<int>& v) { std::sort(v.begin(), v.end()); });
    std::sort(ret.begin(), ret.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
        for (size_t i = 0; i < lhs.size(); ++i) {
            if (lhs[i] < rhs[i]) return true;
        }
        return false;
    });
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
    test({1, 1, 2}, {{1, 1, 2}, {1, 2, 1}, {2, 1, 1}});
    test({1, 2, 3}, {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}});
    test({0, 1}, {{0, 1}, {1, 0}});
    test({1}, {{1}});
    return 0;
}
