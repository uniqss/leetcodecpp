#include "../inc.h"

class Solution {
   public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
        vector<int> ret;
        deque<pair<int, int>> q;
        // 覆盖数量
        int covercount = 0;
        for (int i = 0; i < k; ++i) {
            covercount = 1;  // 至少为1，自己1个
            while (!q.empty() && q.back().first < nums[i]) {
                covercount += q.back().second;
                q.pop_back();
            }
            q.push_back({nums[i], covercount});
        }
        ret.emplace_back(q.front().first);
        for (int i = k; i < nums.size(); ++i) {
            covercount = 1;
            while (!q.empty() && q.back().first < nums[i]) {
                covercount += q.back().second;
                q.pop_back();
            }
            q.push_back({nums[i], covercount});
            if (--q.front().second == 0) q.pop_front();
            ret.emplace_back(q.front().first);
        }
        return ret;
    }
};

void test(const vector<int>& nums, int k, const vector<int>& expect) {
    Solution s;
    auto ret = s.maxSlidingWindow(nums, k);
    if (ret == expect) {
        praw("ok");
    } else {
        praw("##### not ok");
        pvraw(nums);
        praw(k);
        pvraw(expect);
        pvraw(ret);
        pnewline();
    }
}

int main() {
    test({7, 2, 4}, 2, {7, 4});
    test({1, 3, -1, -3, 5, 3, 6, 7}, 3, {3, 3, 5, 5, 6, 7});
    test({1}, 1, {1});
    return 0;
}
