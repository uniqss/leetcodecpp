#include "../inc.h"

class Solution {
   public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());
        for (size_t i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) return false;
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
