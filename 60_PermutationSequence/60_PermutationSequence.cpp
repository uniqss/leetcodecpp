#include "../inc.h"

class Solution {
   public:
    string getPermutation(int n, int k) {
    }
};

void test(int n, int k, const string& expect) {
    Solution so;
    auto ret = so.getPermutation(n, k);
    if (ret == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        praw(n);
        praw(k);
        praw(expect);
        praw(ret);
    }
}

int main() {
    test(3, 3, "213");
    test(4, 9, "2314");
    test(3, 1, "123");
    return 0;
}
