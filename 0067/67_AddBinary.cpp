#include "../inc.h"

class Solution {
   public:
    string addBinary(string a, string b) {}
};

void test(string a, string b, string expect) {
    save4print(a, b);
    assert_eq_ret(expect, Solution().addBinary(a, b));
}

int main() {
    test("11", "1", "100");
    test("1010", "1011", "10101");
    return 0;
}
