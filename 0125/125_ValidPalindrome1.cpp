#include "../inc.h"

class Solution {
   public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        auto alphanumeric = [](char c) {
            return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
        };
        auto clower = [](char c) { return (c >= 'A' && c <= 'Z') ? (c | 0x20) : c; };

        while (l < r) {
            if (!alphanumeric(s[l])) {
                ++l;
                continue;
            }
            if (!alphanumeric(s[r])) {
                --r;
                continue;
            }
            if (clower(s[l]) != clower(s[r])) return false;
            ++l, --r;
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
