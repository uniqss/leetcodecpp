#include "../inc.h"

class Solution {
   public:
    string removeStars(string s) {}
};

void test(string s, string expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().removeStars(s));
}

int main() {
    test("leet**cod*e", "lecoe");
    test("erase*****", "");
    return 0;
}
