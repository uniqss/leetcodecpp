#include "../inc.h"

class Solution {
   public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        uint8_t dict[256] = {0};
        for (auto c : s1) {
            ++dict[c];
        }
        for (auto c : s2) {
            --dict[c];
        }
        for (auto it : dict) {
            if (it != 0) return false;
        }
        return true;
    }
};

void test(std::string s1, std::string s2, bool expect) {
    save4print(s1, s2);
    assert_eq_ret(expect, Solution().CheckPermutation(s1, s2));
}

int main() {
    test("abc", "bca", true);
    test("abc", "bad", false);
    return 0;
}
