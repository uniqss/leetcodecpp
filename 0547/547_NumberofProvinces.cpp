#include "../inc.h"

class Solution {
   public:
    int findCircleNum(vector<vector<int>>& isConnected) {}
};

void test(vector<vector<int>>&& isConnected, int expect) {
    save4print(isConnected);
    assert_eq_ret(expect, Solution().findCircleNum(isConnected));
}

int main() {
    test({{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}}, 1);
    test({{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}, 2);
    test({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, 3);
    return 0;
}
