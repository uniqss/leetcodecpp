#include "../inc.h"

class Solution {
   public:
    bool isPalindrome(string s) {}
};

void test(string s, bool expect) {
    Solution so;
    auto ret = so.isPalindrome(s);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(s);
        print(expect);
        print(ret);
    }
}

int main() {
    test("A man, a plan, a canal: Panama", true);
    test("race a car", false);
    test(" ", true);
    return 0;
}
