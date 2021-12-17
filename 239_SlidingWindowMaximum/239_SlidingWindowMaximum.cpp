#include "../stl.h"

class Solution {
   public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
        deque<pair<int, int>> mq;
        vector<int> ret;
        for (size_t i = 0; i < nums.size(); ++i) {
            int count = 0;
            while (!mq.empty() && mq.back().first < nums[i]) {
                count += mq.back().second + 1;
                mq.pop_back();
            }
            mq.push_back({nums[i], count});

            if ((int)i >= k) {
                if (mq.front().second > 0)
                    --mq.front().second;
                else
                    mq.pop_front();
            }

            if ((int)i >= k - 1) {
                ret.push_back(mq.front().first);
            }
        }
        return ret;
    }
};

void test(const vector<int>& nums, int k, const vector<int>& expect) {
    pvi(nums);
    pi(k);
    Solution s;
    auto ret = s.maxSlidingWindow(nums, k);
    if (ret == expect) {
        ps("ok");
    } else {
        ps("##### not ok");
        pvi(expect);
        pvi(ret);
    }
    pnewline();
}

int main() {
    test({7, 2, 4}, 2, {7, 4});
    test({1, 3, -1, -3, 5, 3, 6, 7}, 3, {3, 3, 5, 5, 6, 7});
    test({1}, 1, {1});
    return 0;
}
