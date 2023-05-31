#include "../inc.h"

class Solution {
   public:
    bool isIsomorphic(string s, string t) {}
};

void test(string s, string t, bool expect) {
    auto sparam = s;
    auto tparam = t;
    Solution so;
    auto ret = so.isIsomorphic(s, t);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(sparam);
        print(tparam);
        print(expect);
        print(ret);
    }
}

int main() {
    test("badc", "baba", false);
    test("egg", "add", true);
    test("foo", "bar", false);
    test("paper", "title", true);
    return 0;
}
