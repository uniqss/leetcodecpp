#include "../inc.h"

class Solution {
   public:
    int findCircleNum(vector<vector<int>>& isConnected) {}
};

void test(vector<vector<int>>&& isConnected, int expect) {
    auto isConnected_param = isConnected;
    Solution so;
    auto ret = so.findCircleNum(isConnected);
    assert_eq_ret(expect, ret);
    print(isConnected_param);
}

int main() {
    test({{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}}, 1);
    test({{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}, 2);
    test({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, 3);
    return 0;
}
