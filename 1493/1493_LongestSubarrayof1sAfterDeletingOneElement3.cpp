#include "../inc.h"

class Solution {
   public:
    int longestSubarray(vector<int>& nums) {
        int currlen = 0, maxlen = 0, count0 = 0;
        queue<int> q;
        for (int n : nums) {
            if (n > 0) {
                ++currlen;
                maxlen = max(maxlen, currlen);
                if (!q.empty() && q.back() > 0)
                    ++q.back();
                else
                    q.push(1);
            } else {
                if (count0 > 0) {
                    if (q.front() > 0) {
                        currlen -= q.front();
                        q.pop();
                    }
                    q.pop();
                    q.push(-1);
                } else {
                    q.push(-1);
                    ++count0;
                }
            }
        }

        return count0 > 0 ? maxlen : maxlen - 1;
    }
};

void test(vector<int>&& nums, int expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.longestSubarray(nums);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(nums_param);
        print(expect);
        print(ret);
    }
}

int main() {
    test({1, 1, 0, 0, 1, 1, 1, 0, 1}, 4);
    test({1, 1, 0, 1}, 3);
    test({0, 1, 1, 1, 0, 1, 1, 0, 1}, 5);
    test({1, 1, 1}, 2);
    return 0;
}
