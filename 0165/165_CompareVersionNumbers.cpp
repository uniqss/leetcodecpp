#include "../inc.h"

class Solution {
   public:
    int compareVersion(string version1, string version2) {}
};

void test(string&& version1, string&& version2, int expect) {
    save4print(version1, version2);
    assert_eq_ret(expect, Solution().compareVersion(version1, version2));
}

int main() {
    test("1.01", "1.001", 0);
    test("1.0", "1.0.0", 0);
    test("0.1", "1.1", -1);
    return 0;
}
