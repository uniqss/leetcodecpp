#include "../inc.h"

class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {}
};

void test(vector<int>&& piles, int h, int expect) {
    save4print(piles, h);
    assert_eq_ret(expect, Solution().minEatingSpeed(piles, h));
}

int main() {
    test({312884470}, 968709470, 1);
    test({3, 6, 7, 11}, 8, 4);
    test({30, 11, 23, 4, 20}, 5, 30);
    test({30, 11, 23, 4, 20}, 6, 23);
    return 0;
}
