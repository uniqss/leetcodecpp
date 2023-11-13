#include "../inc.h"

class Solution {
   public:
    vector<int> countBits(int n) {}
};

void test(int n, vector<int>&& expect) {
    Solution so;
    auto ret = so.countBits(n);
    assert_eq_ret(expect, ret);
    print(n);
}

int main() {
    test(2, {0, 1, 1});
    test(5, {0, 1, 1, 2, 1, 2});
    return 0;
}