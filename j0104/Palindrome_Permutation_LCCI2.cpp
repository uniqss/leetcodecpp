#include "../inc.h"

class Solution {
   public:
    bool canPermutePalindrome(string s) {
        std::unordered_map<char, int> dict;
        for (auto c : s) {
            ++dict[c];
        }
        bool hasOdd = false;
        for (auto it : dict) {
            if (it.second % 2 != 0) {
                if (hasOdd) return false;
                hasOdd = true;
            }
        }
        return true;
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
