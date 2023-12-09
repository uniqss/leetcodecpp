#include "../inc.h"

class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {}
};

void test(vector<int>&& cardPoints, int k, int exepect) {
    save4print(cardPoints, k);
    assert_eq_ret(exepect, Solution().maxScore(cardPoints, k));
}

int main() {
    test({1, 2, 3, 4, 5, 6, 1}, 3, 12);
    test({2, 2, 2}, 2, 4);
    test({9, 7, 7, 9, 7, 7, 9}, 7, 55);
}
