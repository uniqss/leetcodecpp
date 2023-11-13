#include "../inc.h"

// 这个算法骨骼清奇，然并卵，击败了5%的cpu 面试官向写此算法者扔了一只柴犬
class Solution {
    struct s4 {
        int lsum = 0, rsum = 0, msum = 0, total = 0;
    };

    s4 get(vector<int>& nums, int l, int r) {
        if (l == r) return {nums[l], nums[l], nums[l], nums[l]};
        int mid = (l + r) >> 1;
        auto sl = get(nums, l, mid), sr = get(nums, mid + 1, r);
        s4 ret;
        ret.lsum = max(sl.lsum, sl.total + sr.lsum);
        ret.rsum = max(sr.rsum, sr.total + sl.rsum);
        ret.msum = max(max(sl.msum, sr.msum), sl.rsum + sr.lsum);
        ret.total = sl.total + sr.total;
        return ret;
    }

   public:
    int maxSubArray(vector<int>& nums) { return get(nums, 0, nums.size() - 1).msum; }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().maxSubArray(nums));
}

int main() {
    test({-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6);
    test({1}, 1);
    test({5, 4, -1, 7, 8}, 23);
    return 0;
}
