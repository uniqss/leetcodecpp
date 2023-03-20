#include "../inc.h"

class Solution {
   public:
    bool isUnique(string astr) {}
};

void test(const std::string& s, bool expect) {
    Solution so;
    auto ret = so.isUnique(s);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok");
        print(s);
        print(expect);
        print(ret);
    }
}

int main() {
    test("leetcode", false);
    test("abc", true);
    return 0;
}
