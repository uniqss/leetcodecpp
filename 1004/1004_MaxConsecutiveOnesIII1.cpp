#include "../inc.h"

class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        int qlen = 0, maxqlen = 0, count0 = 0;
        queue<int> q;
        for (int num : nums) {
            if (num == 1) {
                ++qlen;
                maxqlen = std::max(maxqlen, qlen);
                if (!q.empty() && q.back() > 0)
                    ++q.back();
                else
                    q.push(1);
            } else {
                if (k == 0) {
                    if (!q.empty()) q.pop();
                    qlen = 0;
                } else {
                    if (count0 >= k) {
                        if (q.front() > 0) {
                            qlen -= q.front();
                            q.pop();
                        }

                        if (!q.empty()) ++q.front();
                        --qlen;
                        if (q.front() == 0) q.pop();
                        --count0;
                    }
                    if (!q.empty() && q.back() < 0)
                        --q.back();
                    else
                        q.push(-1);
                    ++count0;
                    ++qlen;
                    maxqlen = std::max(maxqlen, qlen);
                }
            }
        }
        return maxqlen;
    }
};

void test(vector<int>&& nums, int k, int expect) {
    save4print(nums, k);
    assert_eq_ret(expect, Solution().longestOnes(nums, k));
}

int main() {
    test({0, 0, 1, 1, 1, 1}, 0, 4);
    test({1, 1, 1, 0, 0, 0, 1, 1, 1, 1}, 0, 4);
    test({1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 2, 6);
    test({0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, 3, 10);
    return 0;
}
