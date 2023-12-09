#include "../inc.h"

class Solution {
   public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {}
};

void test(vector<vector<int>>&& roads, int seats, long long expect) {
    save4print(roads, seats);
    assert_eq_ret(expect, Solution().minimumFuelCost(roads, seats));
}

int main() {
    test({{0, 1}, {0, 2}, {1, 3}, {1, 4}}, 5, 4);
    test({{0, 1}, {0, 2}, {0, 3}}, 5, 3);
    test({{3, 1}, {3, 2}, {1, 0}, {0, 4}, {0, 5}, {4, 6}}, 2, 7);
    return 0;
}
