#include "../inc.h"

class Solution {
   public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {}
};

void test(vector<int>&& maxHeights, long long expect) {
    save4print(maxHeights);
    assert_eq_ret(expect, Solution().maximumSumOfHeights(maxHeights));
}

int main() {
    test({6, 5, 2, 1, 5, 4, 4, 2}, 19);
    test({3, 5, 3, 5, 1, 5, 4, 4, 4}, 22);
    test({5, 3, 4, 1, 1}, 13);
    test({6, 5, 3, 9, 2, 7}, 22);
    test({3, 2, 5, 5, 2, 3}, 18);
    return 0;
}
