#include "../inc.h"

class Solution {
   public:
    bool CheckPermutation(string s1, string s2) {}
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
