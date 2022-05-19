#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {}
};

void test(int n, vector<vector<int>>&& expect) {
    Solution so;
    auto ret = so.generateMatrix(n);
    if (ret == expect) {
        praw("ok");
    } else {
        praw("not ok.");
        praw(n);
        pvvraw(expect);
        pvvraw(ret);
        pnewline();
    }
}

int main() {
    test(4, {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}});
    test(3, {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}});
    test(1, {{1}});
    return 0;
}
