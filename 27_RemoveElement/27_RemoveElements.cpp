#include "../inc.h"


class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};

void test(vector<int>&& nums, int val, int expected) {
    Solution so;
    auto ret = so.removeElement(nums, val);
    if (ret == expected) {
        praw("ok");
    } else {
        praw("not ok.");
        pvraw(nums);
        praw(val);
        praw(expected);
        pnewline();
    }
}

int main() {
    test({3, 2, 2, 3}, 3, 2);
    test({0, 1, 2, 2, 3, 0, 4, 2}, 2, 5);

    return 0;
}
