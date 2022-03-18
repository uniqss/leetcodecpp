#include "../stl.h"

/*
没啥好说的，注意 <= 和 +1 -1的trick
*/
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int ret = -1;
        if (nums.size() == 0) return ret;
        int left = 0, right = nums.size() - 1;
        int pivot = 0;
        while (left <= right) {
            pivot = (left + right) / 2;
            if (nums[pivot] == target) return pivot;
            if (nums[pivot] < target)
                left = pivot + 1;
            else
                right = pivot - 1;
        }
        return ret;
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
