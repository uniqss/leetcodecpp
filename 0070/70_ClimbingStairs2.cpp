#include "../inc.h"

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
    save4print(n);
    assert_eq_ret(expect, Solution().climbStairs(n));
}

int main() {
    test(2, 2);
    test(3, 3);
    test(4, 5);
    test(5, 8);
    test(10, 89);

    return 0;
}
