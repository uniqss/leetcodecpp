#include "../inc.h"

class Solution {
   public:
    bool wordPattern(string pattern, string s) {}
};

void test(string pattern, string s, bool expect) {
    save4print(pattern, s);
    assert_eq_ret(expect, Solution().wordPattern(pattern, s));
}

int main() {
    test("jquery", "jquery", false);
    test("abba", "dog dog dog dog", false);  // 这里还要check互相不相等。。。
    test("abba", "dog cat cat dog", true);
    test("abba", "dog cat cat fish", false);
    test("aaaa", "dog cat cat dog", false);

    return 0;
}
