#include "../inc.h"

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int pick = 0;
int guess(int num) {
    if (num == pick) return 0;
    return num > pick ? -1 : 1;
}

class Solution {
   public:
    int guessNumber(int n) {
        // 1 <= pick <= n 不讲武德
        int l = 1, r = n, ret;
        while (true) {
            n = l + (r - l + 1) / 2;
            ret = guess(n);
            if (ret == 0) return n;
            if (ret < 0) {
                r = n - 1;
            } else {
                l = n + 1;
            }
        }

        return -1;
    }
};

void test(int n, int expect) {
    save4print(n);
    pick = expect;
    assert_eq_ret(expect, Solution().guessNumber(n));
}

int main() {
    test(10, 6);
    test(1, 1);
    test(2, 1);
    return 0;
}
