#include "../inc.h"

class Solution {
   public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int top = 1;
        int after = 1;
        int tmp = 0;
        for (int i = 2;i <= n;++i) {
            tmp = top + after;
            after = top;
            top = tmp;
        }
        return top;
    }
};

void test(int n, int expect) {
    Solution so;
    auto ret = so.climbStairs(n);
    if (ret == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        praw(n);
        praw(expect);
        praw(ret);
        pnewline();
    }
}

int main() {
    test(2, 2);
    test(3, 3);
    test(4, 5);
    test(5, 8);
    test(10, 89);

    return 0;
}
