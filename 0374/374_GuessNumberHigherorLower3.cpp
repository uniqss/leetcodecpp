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
        int l = 0, r = n, curr;
        // [] 正解1
        while (l <= r) {
            curr = l + (r - l) / 2;
            int g = guess(curr);
            if (g < 0) {
                r = curr - 1;
            } else if (g > 0) {
                l = curr + 1;
            } else {
                return curr;
            }
        }
        return -1;
    }
};

void test(int n, int expect) {
    pick = expect;
    Solution so;
    auto ret = so.guessNumber(n);
    assert_eq_ret(expect, ret);
    print(n);
}

int main() {
    test(3, 1);
    test(10, 6);
    test(1, 1);
    test(2, 1);
    return 0;
}
