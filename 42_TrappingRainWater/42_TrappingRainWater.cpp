#include "../inc.h"

class Solution {
   public:
    int trap(vector<int>& height) {}
};

void test(vector<int>&& vi, int expect) {
    Solution s;
    int ret = s.trap(vi);
    if (ret == expect) {
        praw("ok");
    } else {
        praw("### not ok ");
        pvraw(vi);
        praw(expect);
        praw(ret);
        pnewline();
    }
}

int main() {
    test({2, 1, 3, 1}, 1);
    test({2, 1, 0, 1, 3, 1}, 4);
    test({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6);
    test({4, 2, 0, 3, 2, 5}, 9);
    return 0;
}
