#include "../inc.h"

class Solution {
   public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {}
};

void test(vector<int>&& flowerbed, int n, bool expect) {
    auto flowerbed_param = flowerbed;
    Solution so;
    auto ret = so.canPlaceFlowers(flowerbed, n);
    assert_eq_ret(expect, ret);
    print(flowerbed_param);
    print(n);
}

int main() {
    test({0, 1, 0}, 1, false);
    test({0}, 1, true);
    test({1, 0, 0, 0, 1, 0, 0}, 2, true);
    test({1, 0, 0, 0, 0, 1}, 2, false);
    test({1, 0, 0, 0, 1}, 1, true);
    test({1, 0, 0, 0, 1}, 2, false);
    return 0;
}
