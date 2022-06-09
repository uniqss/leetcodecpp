#include "inc.h"

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        unordered_set<int> setMaxNum;
        int i = 0;
        int j = 0;
        int k = 0;
        for (; i < nums.size() - 2; ++i) {
            for (j = i + 1; j < nums.size() - 1; ++j) {
                for (k = j + 1; k < nums.size(); ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        int max = std::max(std::max(nums[i], nums[j]), nums[k]);
                        if (setMaxNum.find(max) != setMaxNum.end()) continue;
                        setMaxNum.insert(max);

                        ret.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        return ret;
    }
};

void test(vector<int>&& nums, vector<vector<int>>&& expect) {
    Solution so;
    auto ret = so.threeSum(nums);
    std::for_each(ret.begin(), ret.end(), [](vector<int>& vi) { std::sort(vi.begin(), vi.end()); });
    std::sort(ret.begin(), ret.end());
    std::for_each(expect.begin(), expect.end(), [](vector<int>& vi) { std::sort(vi.begin(), vi.end()); });
    std::sort(expect.begin(), expect.end());
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
    test({-2, 0, 0, 2, 2}, {{-2, 0, 2}});
    test({-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}});
    test({}, {});
    test({0}, {});
    test({3, 0, -2, -1, 1, 2}, {{3, -1, -2}, {2, -2, 0}, {1, -1, 0}});

    return 0;
}
