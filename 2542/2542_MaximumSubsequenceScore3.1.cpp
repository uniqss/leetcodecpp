#include "../inc.h"

class Solution {
   public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // 思路：pair[n1, n2]组成pair加入新数组，新数组按n2的大小从大到小排序(这一步可以保证min值的正确性)
        // 这样当我们循环到新数组某个元素时，被乘的最小的就是当前的n2，问题退化一维到找出前面所有n1里的最大k和ksum
        int n = nums1.size();
        vector<pair<int, int>> dict(n);
        for (int i = 0; i < n; ++i) dict[i] = {nums1[i], nums2[i]};
        sort(dict.begin(), dict.end(),
             [](const pair<int, int>& lhs, const pair<int, int>& rhs) { return lhs.second > rhs.second; });
        priority_queue<int, vector<int>, greater<int>> q;
        long long sum = 0, smax = 0;
        for (auto [n1, n2] : dict) {
            sum += n1;
            q.emplace(n1);
            if (q.size() > k) sum -= q.top(), q.pop();
            if (q.size() == k) smax = max(smax, sum * n2);
        }
        return smax;
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
