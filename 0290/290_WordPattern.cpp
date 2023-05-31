#include "../inc.h"

class Solution {
   public:
    bool wordPattern(string pattern, string s) {}
};

void test(string pattern, string s, bool expect) {
    Solution so;
    auto ret = so.wordPattern(pattern, s);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(pattern);
        print(s);
        print(expect);
        print(ret);
    }
}

int main() {
    test("abba", "dog dog dog dog", false);  // 这里还要check互相不相等。。。
    test("abba", "dog cat cat dog", true);
    test("abba", "dog cat cat fish", false);
    test("aaaa", "dog cat cat dog", false);

    return 0;
}
