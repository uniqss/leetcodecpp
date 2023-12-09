#include "../inc.h"

class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {}
};

void test(string s1, string s2, string s3, bool expect) {
    save4print(s1, s2, s3);
    assert_eq_ret(expect, Solution().isInterleave(s1, s2, s3));
}

int main() {
    test("", "", "a", false);
    test("aabcc", "dbbca", "aadbbcbcac", true);
    test("aabcc", "dbbca", "aadbbbaccc", false);
    test("", "", "", true);
    return 0;
}
