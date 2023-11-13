#include "../inc.h"

class Solution {
   public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int left = 1;   // 0. left foot behind
        int right = 1;  // 1. right foot ahead
        for (int i = 2; i <= (n + 1) / 2; ++i) {
            // move left foot
            left += right;
            // move right foot
            right += left;
        }
        // we need to move one more step if the last is the left foot.
        return n % 2 == 0 ? (left + right) : right;
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
