#include "../inc.h"

class Solution {
   public:
    string intToRoman(int num) {}
};

void test(int num, string expect) {
    save4print(num);
    Solution so;
    auto ret = so.intToRoman(num);
    assert_eq_ret(expect, ret);
}

int main() {
    test(400, "CD");
    test(3, "III");
    test(58, "LVIII");
    test(1994, "MCMXCIV");
    return 0;
}
