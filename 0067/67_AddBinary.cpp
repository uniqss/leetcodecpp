#include "../inc.h"

class Solution {
   public:
    string addBinary(string a, string b) {}
};

void test(string a, string b, string expect) {
    Solution so;
    auto ret = so.addBinary(a, b);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(a);
        print(b);
        print(expect);
        print(ret);
    }
}

int main() {
    test("11", "1", "100");
    test("1010", "1011", "10101");
    return 0;
}
