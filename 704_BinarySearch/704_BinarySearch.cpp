#include "../stl.h"

class Solution {
   public:
    int search(vector<int>& nums, int target) {
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
