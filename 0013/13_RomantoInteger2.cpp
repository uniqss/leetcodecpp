#include "../inc.h"

class Solution {
   public:
    int romanToInt(string s) {
        unordered_map<char, int> d2 = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int ret = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            int value = d2[s[i]];
            if (i < n - 1 && value < d2[s[i + 1]]) {
                ret -= value;
            } else {
                ret += value;
            }
        }
        return ret;
    }
};

void test(string s, int expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().romanToInt(s));
}

int main() {
    test("MCDLXXVI", 1476);
    test("III", 3);
    test("LVIII", 58);
    test("MCMXCIV", 1994);
    return 0;
}