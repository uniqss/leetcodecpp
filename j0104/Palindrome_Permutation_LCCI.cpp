#include "../inc.h"

class Solution {
   public:
    bool canPermutePalindrome(string s) {}
};

void test(std::string&& s, bool expect) {
    Solution so;
    auto ret = so.canPermutePalindrome(s);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(s);
        print(expect);
        print(ret);
    }
}

int main() {
    test("aab", true);
    test("tactcoa", true);
    return 0;
}
