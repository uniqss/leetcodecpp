#include "../inc.h"

class Solution {
   public:
    int romanToInt(string s) {
        unordered_map<string, int> d1 = {{"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};
        unordered_map<char, int> d2 = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int ret = 0, pos = 0, ssize = s.size();
        while (true) {
            if (ssize - pos >= 2) {
                auto it = d1.find(s.substr(pos, 2));
                if (it != d1.end()) {
                    pos += 2;
                    ret += it->second;
                    continue;
                }
            }
            if (ssize - pos >= 1) {
                auto it = d2.find(s[pos]);
                if (it != d2.end()) {
                    pos += 1;
                    ret += it->second;
                    continue;
                }
            }
            break;
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