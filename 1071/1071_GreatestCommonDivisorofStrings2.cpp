#include "../inc.h"

class Solution {
   public:
    string gcdOfStrings(string str1, string str2) {
        int size1 = str1.size(), size2 = str2.size(), msize = std::min(size1, size2), same = 0;
        while (same < msize && str1[same] == str2[same]) ++same;

        auto gcdeq = [](const string& str, int size, int gcd) {
            for (int i = 1; i < size / gcd; ++i) {
                for (int j = 0; j < gcd; ++j) {
                    if (str[j] != str[i * gcd + j]) return false;
                }
            }
            return true;
        };
        for (int g = same; g >= 1; --g) {
            if (size1 % g != 0 || size2 % g != 0) continue;
            if (gcdeq(str1, size1, g) && gcdeq(str2, size2, g)) return str1.substr(0, g);
        }
        return "";
    }
};

void test(string&& str1, string&& str2, const string& expect) {
    save4print(str1, str2);
    assert_eq_ret(expect, Solution().gcdOfStrings(str1, str2));
}

int main() {
    test("ABCABC", "ABC", "ABC");
    test("ABABAB", "ABAB", "AB");
    test("LEET", "CODE", "");
    return 0;
}
