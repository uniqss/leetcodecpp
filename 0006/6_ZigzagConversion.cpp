#include "../inc.h"

class Solution {
   public:
    string convert(string s, int numRows) {}
};

void test(string s, int numRows, string expect) {
    save4print(s);
    save4print(numRows);
    Solution so;
    auto ret = so.convert(s, numRows);
    assert_eq_ret(expect, ret);
}

int main() {
    test("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");
    test("PAYPALISHIRING", 4, "PINALSIGYAHRPI");
    test("A", 1, "A");
    return 0;
}
