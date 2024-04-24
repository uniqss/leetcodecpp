#include "../inc.h"

class Solution {
   public:
    bool canPermutePalindrome(string s) {
        int dict[256] = {0};
        int oddCount = 0;
        for (auto c : s) {
            ++dict[c];
            if (dict[c] % 2 == 0) {
                --oddCount;
            } else {
                ++oddCount;
            }
        }
        return oddCount <= 1;
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
