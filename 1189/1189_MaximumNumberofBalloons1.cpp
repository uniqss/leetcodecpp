#include "../inc.h"

class Solution {
   public:
    int maxNumberOfBalloons(string text) {
        vector<int> dict(26);
        for (char c : text) ++dict[c - 'a'];
        int ret = dict['b' - 'a'];
        ret = min(ret, dict['a' - 'a']);
        ret = min(ret, dict['l' - 'a'] / 2);
        ret = min(ret, dict['o' - 'a'] / 2);
        ret = min(ret, dict['n' - 'a']);
        return ret;
    }
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
