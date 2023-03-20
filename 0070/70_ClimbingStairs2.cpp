#include "../inc/inc.h"

class Solution {
   public:
    int climbStairs(int n) {
        vector<int> vi(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            vi[i] = vi[i - 1] + vi[i - 2];
        }
        return vi[n];
    }
};

void test(int n, int expect) {
    Solution so;
    auto ret = so.climbStairs(n);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(n);
        print(expect);
        print(ret);
        print();
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
