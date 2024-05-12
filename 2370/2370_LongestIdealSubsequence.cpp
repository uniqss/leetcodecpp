#include "../inc.h"

class Solution {
   public:
    int longestIdealString(string s, int k) {}
};

void test(string&& s, int k, int expect) {
    save4print(s, k);
    assert_eq_ret(expect, Solution().longestIdealString(s, k));
}

int main() {
    test("acfgbd", 2, 4);
    test("abcd", 3, 4);
    test("lkpkxcigcs", 6, 7);
    return 0;
}
