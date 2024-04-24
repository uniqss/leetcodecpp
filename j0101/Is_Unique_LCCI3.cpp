#include "../inc.h"

class Solution {
   public:
    bool isUnique(string astr) {
        uint8_t dict[256] = {0};
        for (const auto c : astr) {
            if (dict[c] > 0) return false;
            dict[c] = 1;
        }
        return true;
    }
};

void test(const std::string& s, bool expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().isUnique(s));
}

int main() {
    test("leetcode", false);
    test("abc", true);
    return 0;
}
