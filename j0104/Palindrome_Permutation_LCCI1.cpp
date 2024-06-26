#include "../inc.h"

class Solution {
   public:
    bool canPermutePalindrome(string s) {
        auto ssize = s.size();
        std::sort(s.begin(), s.end());
        int count = 0;
        bool hasOdd = false;
        for (size_t i = 0; i < ssize; ++i) {
            if (i > 0 && s[i] != s[i - 1]) {
                if (count % 2 != 0) {
                    if (hasOdd) return false;
                    hasOdd = true;
                    count = 0;
                }
            }
            ++count;
        }
        return count % 2 == 0 || !hasOdd;
    }
};

void test(std::string&& s, bool expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().canPermutePalindrome(s));
}

int main() {
    test("code", false);
    test("aab", true);
    test("tactcoa", true);
    return 0;
}
