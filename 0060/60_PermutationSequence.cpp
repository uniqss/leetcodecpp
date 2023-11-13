#include "../inc.h"

class Solution {
   public:
    string getPermutation(int n, int k) {}
};

void test(int n, int k, const string& expect) {
    save4print(n, k);
    assert_eq_ret(expect, Solution().getPermutation(n, k));
}

int main() {
    test(3, 3, "213");
    test(4, 9, "2314");
    test(3, 1, "123");
    return 0;
}
