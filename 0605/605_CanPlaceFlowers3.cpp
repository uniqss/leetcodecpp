#include "../inc.h"

class Solution {
   public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        if (flowerbed.size() == 1) return flowerbed[0] == 0;
        int fsize = flowerbed.size();
        for (int i = 0; i < fsize; ++i) {
            if (flowerbed[i] > 0) continue;
            if (i == 0) {
                if (flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    if (--n <= 0) return true;
                }
            } else if (i == fsize - 1) {
                if (flowerbed[i - 1] == 0) {
                    flowerbed[i] = 1;
                    if (--n <= 0) return true;
                }
            } else {
                if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    if (--n <= 0) return true;
                }
            }
        }
        return false;
    }
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
    test({1, 0, 1, 0, 1, 0, 1}, 0, true);
    return 0;
}
