#include "../inc.h"

class Solution {
   public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {}
};

void test(vector<string>&& digits, int n, int expect) {
    save4print(digits, n);
    assert_eq_ret(expect, Solution().atMostNGivenDigitSet(digits, n));
}
int main() {
    test({"1", "3", "5", "7"}, 100, 20);
    test({"1", "4", "9"}, 1000000000, 29523);
    test({"7"}, 8, 1);
    return 0;
}