#include "../inc.h"

// 临场本来想用一个start，结果跳下一个的逻辑不好处理，直接deque了，简单明了
class Solution {
   public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), vmax = 0;
        for (int v : nums) vmax = max(vmax, v);
        deque<int> q;
        long long ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == vmax) q.emplace_back(i);
            if (q.size() > k) q.pop_front();
            if (q.size() == k) print(q.front() + 1), ret += q.front() + 1;
        }
        return ret;
    }
};

void test(vector<int>&& nums, int k, long long expect) {
    save4print(nums, k);
    assert_eq_ret(expect, Solution().countSubarrays(nums, k));
}

int main() {
    test({61,23,38,23,56,40,82,56,82,82,82,70,8,69,8,7,19,14,58,42,82,10,82,78,15,82}, 2, 224);
    test({1, 3, 2, 3, 3}, 2, 6);
    test({1, 4, 2, 1}, 3, 0);
    return 0;
}
