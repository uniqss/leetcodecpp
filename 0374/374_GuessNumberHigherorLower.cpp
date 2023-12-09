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
    int guessNumber(int n) {}
};

void test(int n, int expect) {
    save4print(n);
    pick = expect;
    assert_eq_ret(expect, Solution().guessNumber(n));
}

int main() {
    test(2147483647, 2147483647);
    test(3, 1);
    test(10, 6);
    test(1, 1);
    test(2, 1);
    return 0;
}
