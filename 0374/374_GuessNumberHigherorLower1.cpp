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
        int l = 1, r = INT_MAX;
        int gret = guess(n);
        if (gret < 0) {
            r = n - 1;
        } else if (gret > 0) {
            l = n + 1;
        }
        while (true) {
            gret = guess(n);
            if (gret == 0) return n;
            if (gret < 0) {
                r = n - 1;
            } else {
                l = n + 1;
            }
            n = l + (r - l + 1) / 2;
        }
        return n;
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
    test(10, 6);
    test(1, 1);
    test(2, 1);
    return 0;
}
