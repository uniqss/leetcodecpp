#include "../stl.h"

class Solution {
   public:
    int search(vector<int>& nums, int target) { return binary_search(nums, target, 0, nums.size() - 1); }
    int binary_search(const vector<int>& nums, int target, int l, int r) {
        if (nums[l] > target || nums[r] < target) return -1;
        int mid = 0;
        while (r >= l) {
            mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) return binary_search(nums, target, l, mid - 1);
            return binary_search(nums, target, mid + 1, r);
        }
        return -1;
    }
};

void test(vector<int>&& nums, int target, int expect) {
    Solution so;
    int ret = so.search(nums, target);
    if (ret == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        pvraw(nums);
        praw(expect);
        praw(ret);
        pnewline();
    }
}

int main() {
    test({-1, 0, 3, 5, 9, 12}, 0, 1);
    test({-1, 0, 3, 5, 9, 12}, 9, 4);
    test({-1, 0, 3, 5, 9, 12}, 2, -1);
    test({5}, 5, 0);
    return 0;
}
/*
[-1,0,3,5,9,12]
9
[-1,0,3,5,9,12]
2
*/
