#include "../inc.h"

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
    }
};

void test(vector<int>&& vi, int expect) {
    Solution s;
    int ret = s.largestRectangleArea(vi);
    if (ret != expect) {
        praw("###### not ok");
        pvraw(vi);
        praw(expect);
        praw(ret);
    } else {
        praw("ok");
    }
    pnewline();
}

int main() {
    test({2, 0, 2}, 2);
    test({2, 1, 5, 6, 2, 3}, 10);
    test({2, 4}, 4);
    test({2, 1, 2}, 3);
    test({5}, 5);
    return 0;
}

/*
[2,1,5,6,2,3]
[2,4]
*/