#include "../inc.h"

class Solution {
   public:
    long long totalCost(vector<int>& costs, int k, int candidates) {}
};

void test(vector<int>&& costs, int k, int candidates, long long expect) {
    save4print(costs, k, candidates);
    assert_eq_ret(expect, Solution().totalCost(costs, k, candidates));
}

int main() {
    test({31, 25, 72, 79, 74, 65, 84, 91, 18, 59, 27, 9, 81, 33, 17, 58}, 11, 2, 423);
    test({10, 1, 11, 10}, 2, 1, 11);
    test({17, 12, 10, 2, 7, 2, 11, 20, 8}, 3, 4, 11);
    test({1, 2, 4, 1}, 3, 3, 4);
    return 0;
}
