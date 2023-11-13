#include "../inc.h"

class Solution {
   public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (!std::isalnum(s[l])) {
                ++l;
                continue;
            }
            if (!std::isalnum(s[r])) {
                --r;
                continue;
            }
            if (tolower(s[l]) == tolower(s[r])) {
                ++l, --r;
                continue;
            } else
                return false;
        }
        return true;
    }
};

void test(string s, bool expect) {
    save4print(s);
    Solution so;
    auto ret = so.isPalindrome(s);
    assert_eq_ret(expect, ret);
}

int main() {
    test("0P", false);
    test("A man, a plan, a canal: Panama", true);
    test("race a car", false);
    test(" ", true);
    return 0;
}
