#include "../inc.h"

class Solution {
   public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {}
};

void test(vector<int>&& flowerbed, int n, bool expect) {
    save4print(flowerbed, n);
    assert_eq_ret(expect, Solution().canPlaceFlowers(flowerbed, n));
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
