#include "../stl.h"

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        // [left, right)的用法 这样逼近的速度其实是要慢一点的，不过思路还是很清晰的，也不太容易出错
        int left = 0, right = nums.size(), mid = 0, vmid = 0;
        while (left < right) {
            int mid = (left + right) / 2;
            int vmid = nums[mid];
            if (vmid == target) return mid;
            if (vmid < target)
                left = mid + 1;
            else
                right = mid;
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
