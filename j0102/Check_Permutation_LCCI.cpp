#include "../inc.h"

class Solution {
   public:
    bool CheckPermutation(string s1, string s2) {}
};

void test(std::string s1, std::string s2, bool expect) {
    Solution so;
    auto ret = so.CheckPermutation(s1, s2);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(s1);
        print(s2);
        print(expect);
        print(ret);
    }
}

int main() {
    test("abc", "bca", true);
    test("abc", "bad", false);
    return 0;
}
