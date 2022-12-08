#include "../inc.h"

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int idx_right_min = -1;
        int right_min = INT_MAX;
        int idx = -1;
        for (int i = (int)nums.size() - 1; i > 0; --i) {
            if (nums[i] > nums[i - 1]) {
                idx = i - 1;
                break;
            }
        }
        if (idx == -1) {
            std::reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = idx + 1; i < (int)nums.size(); ++i) {
            if (nums[i] <= nums[idx]) continue;
            if (nums[i] < right_min) {
                idx_right_min = i;
                right_min = nums[i];
            }
        }

        swap(nums[idx], nums[idx_right_min]);
        if (idx_right_min > 0) std::sort(nums.begin() + idx + 1, nums.end());
    }
};

void test(vector<int>&& nums, vector<int>&& expect) {
    Solution so;
    vector<int> nums_saved = nums;

    so.nextPermutation(nums);
    if (nums == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(nums_saved);
        print(expect);
        print(nums);
    }
}

int main() {
    test({1, 5, 1}, {5, 1, 1});
    test({3, 2, 1}, {1, 2, 3});
    test({3, 1, 2}, {3, 2, 1});
    test({2, 3, 1}, {3, 1, 2});
    test({1, 2, 3}, {1, 3, 2});
    test({1, 1, 5}, {1, 5, 1});
    return 0;
}
