#include "../inc.h"

// backtrack算法是ok的，但是会超时、超内存
class Solution {
    long long ret = 0;

   public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        multiset<int> ms;
        ret = 0;
        unordered_set<int> selected;
        helper(nums1, nums2, k, 0, 0, ms, selected);
        return ret;
    }
    void helper(vector<int>& nums1, vector<int>& nums2, int k, int curr, long long sum, multiset<int>& ms,
                unordered_set<int>& selected) {
        if (selected.size() == k) {
            long long curr = sum * *ms.begin();
            ret = max(ret, curr);
            return;
        }

        if (curr >= nums1.size()) return;

        // select curr
        selected.insert(curr);
        sum += nums1[curr];
        ms.insert(nums2[curr]);
        helper(nums1, nums2, k, curr + 1, sum, ms, selected);

        selected.erase(curr);
        sum -= nums1[curr];
        ms.erase(ms.find(nums2[curr]));

        // don't select curr
        helper(nums1, nums2, k, curr + 1, sum, ms, selected);
    }
};

void test(vector<int>&& nums1, vector<int>&& nums2, int k, long long expect) {
    save4print(nums1, nums2, k);
    assert_eq_ret(expect, Solution().maxScore(nums1, nums2, k));
}

int main() {
    test({79, 76, 41, 28, 41, 66, 44, 30, 25}, {25, 0, 69, 67, 55, 0, 9, 77, 26}, 7, 2592);
    test({1, 3, 3, 2}, {2, 1, 3, 4}, 3, 12);
    test({4, 2, 3, 1, 1}, {7, 5, 10, 9, 6}, 1, 30);
    return 0;
}
