#include "../inc.h"

class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        int qlen = 0, maxqlen = 0, count0 = 0;
        deque<int> q;
        for (int num : nums) {
            if (num == 1) {
                ++qlen;
                maxqlen = std::max(maxqlen, qlen);
                if (!q.empty() && q.back() > 0)
                    ++q.back();
                else
                    q.push_back(1);
            } else {
                if (count0 >= k) {
                    if (q.front() > 0) {
                        qlen -= q.front();
                        q.pop_front();
                    }

                    ++q.front();
                    --qlen;
                    if (q.front() == 0) q.pop_front();
                }
                if (!q.empty() && q.back() < 0)
                    --q.back();
                else
                    q.push_back(-1);
            }
        }
    }
};

void test(vector<int>&& nums, int k, int expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.longestOnes(nums, k);
    assert_eq_ret(expect, ret);
    print(nums_param);
    print(k);
}

int main() {
    test({1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 2, 6);
    test({0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, 3, 10);
    return 0;
}
