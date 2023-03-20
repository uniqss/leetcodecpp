#include "../inc/inc.h"

class Solution {
   public:
    string reverseStr(string s, int k) {}
};

void test(string&& s, int k, const string& expect) {
    Solution so;
    auto ret = so.reverseStr(s, k);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(s);
        print(k);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test("abcdefg", 8, "gfedcba");
    test("abcdefg", 2, "bacdfeg");
    test("abcd", 2, "bacd");
    return 0;
}
