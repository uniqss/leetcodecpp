#include "../inc/inc.h"

class Solution {
   public:
    string reverseWords(string s) {}
};

void test(string&& s, string expect) {
    Solution so;
    auto ret = so.reverseWords(s);
    if (expect == ret) {
        print("ok");
    } else {
        print("not ok.");
        print(s);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test("a", "a");
    test("the sky is blue", "blue is sky the");
    test("  hello world  ", "world hello");
    test("a good   example", "example good a");
    test("example good a", "a good example");
    return 0;
}
