#include "../inc.h"

class Solution {
   public:
    int count(string num1, string num2, int min_sum, int max_sum) {}
};

void test(string num1, string num2, int min_sum, int max_sum, int expect) {
    save4print(num1, num2, min_sum, max_sum);
    assert_eq_ret(expect, Solution().count(num1, num2, min_sum, max_sum));
}

int main() {
    test("4179205230", "7748704426", 8, 46, 883045899);
    test("1", "12", 1, 8, 11);
    test("1", "5", 1, 5, 5);
    return 0;
}