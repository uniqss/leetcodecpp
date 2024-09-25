#include "../inc.h"

class Solution {
   public:
    int maxNumberOfBalloons(string text) {}
};

void test(string&& text, int expect) {
    save4print(text);
    assert_eq_ret(expect, Solution().maxNumberOfBalloons(text));
}

int main() {
    test("nlaebolko", 1);
    test("loonbalxballpoon", 2);
    test("leetcode", 0);
    return 0;
}
