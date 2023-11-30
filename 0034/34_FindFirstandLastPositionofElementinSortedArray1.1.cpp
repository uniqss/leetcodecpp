#include "../inc.h"

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = bsearch_first_ge(nums, target);
        if (l < 0 || nums[l] != target) return {-1, -1};
        int r = bsearch_last_le(nums, target);
        return {l, r};
    }
    int bsearch_first_ge(const vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int l = 0, r = nums.size() - 1, mid;
        if (nums[l] >= target) return l;
        if (nums[r] < target) return -1;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    int bsearch_last_le(const vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int l = 0, r = nums.size() - 1, mid;
        if (nums[r] <= target) return r;
        if (nums[l] > target) return -1;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};

void test(vector<int>&& nums, int target, const vector<int>& expect) {
    save4print(nums, target);
    assert_eq_ret(expect, Solution().searchRange(nums, target));
}

int main() {
    test({5, 7, 7, 8, 8, 10}, 8, {3, 4});
    test({5, 7, 7, 8, 8, 10}, 6, {-1, -1});
    test({1}, 0, {-1, -1});
    test({1}, 1, {0, 0});
    test({1}, 2, {-1, -1});
    test({}, 0, {-1, -1});
    return 0;
}