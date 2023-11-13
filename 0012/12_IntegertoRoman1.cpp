#include "../inc.h"

class Solution {
   public:
    string intToRoman(int num) {
        vector<pair<int, string>> dict = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
                                          {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
                                          {5, "V"},    {4, "IV"},   {1, "I"}};
        string ret;
        while (num > 0) {
            for (const auto& [val, str] : dict) {
                if (num >= val) {
                    num -= val;
                    ret += str;
                    break;
                }
            }
        }

        return ret;
    }
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
