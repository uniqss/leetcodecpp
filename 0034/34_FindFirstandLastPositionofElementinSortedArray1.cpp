#include "../inc.h"

// 注意这个代码很重要，upper_bound/lower_bound可以直接用到项目里(当然也可以用stl的，更倾向于用自己写的)
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int u = upper_bound(nums, target);
        int l = lower_bound(nums, target);
        if (u == -1 || nums[u] != target) return {-1, -1};
        return {u, l};
    }
    // first >= target
    int upper_bound(const vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        if (nums[l] == target) return l;
        if (nums[r] < target) return -1;

        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    // first <= target
    int lower_bound(const vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        if (nums[r] == target) return r;
        if (nums[l] > target) return -1;

        while (l <= r) {
            mid = (l + r) / 2;
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
    test({}, 0, {-1, -1});
    return 0;
}