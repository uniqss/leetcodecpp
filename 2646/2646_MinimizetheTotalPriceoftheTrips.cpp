#include "../inc.h"

class Solution {
   public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price,
                          vector<vector<int>>& trips) {}
};

void test(int n, vector<vector<int>>&& edges, vector<int>&& price, vector<vector<int>>&& trips,
          int expect) {
    save4print(n, edges, price, trips);
    assert_eq_ret(expect, Solution().minimumTotalPrice(n, edges, price, trips));
}

int main() {
    test(4, {{0, 1}, {1, 2}, {1, 3}}, {2, 2, 10, 6}, {{0, 3}, {2, 1}, {2, 3}}, 23);
    test(2, {{0, 1}}, {2, 2}, {{0, 0}}, 1);
    return 0;
}
