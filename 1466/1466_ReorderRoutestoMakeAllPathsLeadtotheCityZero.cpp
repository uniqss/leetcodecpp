#include "../inc.h"

class Solution {
   public:
    int minReorder(int n, vector<vector<int>>& connections) {}
};

void test(int n, vector<vector<int>>&& connections, int expect) {
    auto connections_param = connections;
    Solution so;
    auto ret = so.minReorder(n, connections);
    assert_eq_ret(expect, ret);
    print(n);
    print(connections_param);
}

int main() {
    test(6, {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}}, 3);
    test(5, {{1, 0}, {1, 2}, {3, 2}, {3, 4}}, 2);
    test(3, {{1, 0}, {2, 0}}, 0);

    return 0;
}
