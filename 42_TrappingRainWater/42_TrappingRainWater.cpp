#include "../stl.h"

class Solution {
   public:
    int trap(vector<int>& height) {
    }
};

void test(vector<int>&& vi, int expect) {
    pvraw(vi);
    Solution s;
    int ret = s.trap(vi);
    if (ret == expect) {
        praw("ok");
    } else {
        praw("### not ok ");
        praw(expect);
        praw(ret);
    }
}

int main() {
    test({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6);
    test({4, 2, 0, 3, 2, 5}, 9);
    return 0;
}

/*
[0,1,0,2,1,0,1,3,2,1,2,1]
[4,2,0,3,2,5]
*/
