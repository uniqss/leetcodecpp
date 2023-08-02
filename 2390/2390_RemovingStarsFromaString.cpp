#include "../inc.h"

class Solution {
   public:
    string removeStars(string s) {}
};

void test(string s, string expect) {
    Solution so;
    auto ret = so.removeStars(s);
    assert_eq_ret(expect, ret);
    print(s);
}

int main() {
    test("leet**cod*e", "lecoe");
    test("erase*****", "");
    return 0;
}
