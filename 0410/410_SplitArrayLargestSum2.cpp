#include "../inc.h"

class Solution {
    bool check(const vector<int>& nums, int sum, int k) {
        int count = 1, currsum = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] > sum) return false;
            currsum += nums[i];
            if (currsum > sum) {
                if (++count > k) return false;
                currsum = nums[i];
            }
        }
        return count <= k;
    }

   public:
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = 1e9, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (check(nums, mid, k)) {
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return l;
    }
};

void test(vector<int>&& nums, int k, int expect) {
    save4print(nums, k);
    assert_eq_ret(expect, Solution().splitArray(nums, k));
}

int main() {
    test({0}, 1, 0);
    test({10, 2, 3}, 2, 10);
    test({1, 4, 4}, 3, 4);
    test({7, 2, 5, 10, 8}, 2, 18);
    test({1, 2, 3, 4, 5}, 2, 9);
    return 0;
}