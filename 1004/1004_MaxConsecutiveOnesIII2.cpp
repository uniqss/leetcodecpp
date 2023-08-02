#include "../inc.h"

class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        int ret = 0, curr = 0, nsize = nums.size(), count0 = 0;
        queue<int> q;
        for (int i = 0; i < nsize; ++i) {
            if (nums[i] != 0) {
                ++curr;
                if (q.empty() || q.back() < 0)
                    q.push(1);
                else
                    ++q.back();
            } else {
                ++curr;
                if (q.empty() || q.back() > 0)
                    q.push(-1);
                else
                    --q.back();
                ++count0;
                if (count0 > k) {
                    --count0;
                    if (q.front() > 0) {
                        curr -= q.front();
                        q.pop();
                    }
                    ++q.front();
                    --curr;
                    if (q.front() == 0) q.pop();
                }
            }
            ret = max(ret, curr);
        }

        return ret;
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
    test({0, 0, 1, 1, 1, 1}, 0, 4);
    test({1, 1, 1, 0, 0, 0, 1, 1, 1, 1}, 0, 4);
    test({1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 2, 6);
    test({0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, 3, 10);
    return 0;
}
