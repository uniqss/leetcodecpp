#include "stl.h"

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
    }
};

void test(vector<int>&& vi, int expect) {
    Solution s;
    int ret = s.largestRectangleArea(vi);
    if (ret != expect) {
        ps("###### not ok");
    } else {
        ps("ok");
    }
    pnewline();
}

void main() {
    test({2, 1, 5, 6, 2, 3}, 10);
    test({2, 4}, 4);
}

/*
[2,1,5,6,2,3]
[2,4]
*/