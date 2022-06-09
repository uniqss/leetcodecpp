#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {}
};

void test(vector<int>&& nums, int target, vector<vector<int>>&& expect) {
    Solution so;
    auto ret = so.fourSum(nums, target);
    for_each(expect.begin(), expect.end(), [](vector<int>& arr) { sort(arr.begin(), arr.end()); });
    std::sort(expect.begin(), expect.end());

    for_each(ret.begin(), ret.end(), [](vector<int>& arr) { sort(arr.begin(), arr.end()); });
    sort(ret.begin(), ret.end());

    if (ret == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        pvraw(nums);
        praw(target);
        pvvraw(expect);
        pvvraw(ret);
        pnewline();
    }
}

int main() {
    test({1, 0, -1, 0, -2, 2}, 0, {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}});
    test({2, 2, 2, 2, 2}, 8, {{2, 2, 2, 2}});
    return 0;
}
