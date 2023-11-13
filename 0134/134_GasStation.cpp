#include "../inc.h"

class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {}
};

void test(vector<int>&& gas, vector<int>&& cost, int expect) {
    save4print(gas, cost);
    assert_eq_ret(expect, Solution().canCompleteCircuit(gas, cost));
}

int main() {
    test({1, 1, 3}, {2, 2, 1}, 2);
    test({4}, {5}, -1);
    // {-2, -2, -2, 3, 3}
    test({4, 5, 3, 1, 4}, {5, 4, 3, 4, 2}, -1);
    test({3, 3, 4}, {3, 4, 4}, -1);
    test({1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}, 3);
    test({2, 3, 4}, {3, 4, 3}, -1);
    return 0;
}