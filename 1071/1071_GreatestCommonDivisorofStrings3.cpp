#include "../inc.h"

class Solution {
   public:
    string gcdOfStrings(string str1, string str2) {
        std::function<int(int, int)> gcd = [&](int i, int j) -> int {
            if (i < j) return gcd(j, i);
            if (i % j == 0) return j;
            return gcd(j, i - j);
        };
        int m = str1.size(), n = str2.size(), mn = gcd(m, n);
        auto same = [](const string& str, int size, int gcd) {
            for (int i = 0; i < gcd; ++i) {
                for (int j = 0; j < size / gcd; ++j) {
                    if (str[i] != str[j * gcd + i]) return false;
                }
            }
            return true;
        };
        int samestart = 0;
        while (str1[samestart] == str2[samestart] && samestart < mn) ++samestart;
        for (int i = samestart; i >= 1; --i) {
            if (m % i != 0 || n % i != 0) continue;
            if (same(str1, m, i) && same(str2, n, i)) return str1.substr(0, i);
        }
        return "";
    }
};

void test(string&& str1, string&& str2, const string& expect) {
    save4print(str1, str2);
    assert_eq_ret(expect, Solution().gcdOfStrings(str1, str2));
}

int main() {
    test("ABABABAB", "ABAB", "ABAB");
    test("ABCABC", "ABC", "ABC");
    test("ABABAB", "ABAB", "AB");
    test("LEET", "CODE", "");
    return 0;
}
