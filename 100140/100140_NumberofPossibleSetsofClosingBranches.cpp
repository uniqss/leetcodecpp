#include "../inc.h"

class Solution {
   public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {}
};

void test(int n, int maxDistance, vector<vector<int>>&& roads, int expect) {
    save4print(n, maxDistance, roads);
    assert_eq_ret(expect, Solution().numberOfSets(n, maxDistance, roads));
}

int main() {
    test(3, 5, {{0, 1, 2}, {1, 2, 10}, {0, 2, 10}}, 5);
    test(3, 5, {{0, 1, 20}, {0, 1, 10}, {1, 2, 2}, {0, 2, 2}}, 7);
    test(1, 10, {}, 2);
    return 0;
}
