#include "../inc.h"

// 巧夺天工，官网解法
class Solution {
    long long ret = 0;

   public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> dict(n);
        for (int i = 0; i < n; ++i) {
            dict[i] = {nums2[i], nums1[i]};
        }
        sort(rbegin(dict), rend(dict));
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, ret = 0;
        for (int i = 0; i < n; ++i) {
            auto [n2, n1] = dict[i];
            sum += n1;
            pq.emplace(n1);
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                ret = max(ret, sum * n2);
            }
        }

        return ret;
    }
};

void test(vector<int>&& nums1, vector<int>&& nums2, int k, long long expect) {
    save4print(nums1, nums2, k);
    assert_eq_ret(expect, Solution().maxScore(nums1, nums2, k));
}

int main() {
    test({2, 1, 14, 12}, {11, 7, 13, 6}, 3, 168);
    test({79, 76, 41, 28, 41, 66, 44, 30, 25}, {25, 0, 69, 67, 55, 0, 9, 77, 26}, 7, 2592);
    test({1, 3, 3, 2}, {2, 1, 3, 4}, 3, 12);
    test({4, 2, 3, 1, 1}, {7, 5, 10, 9, 6}, 1, 30);
    return 0;
}
