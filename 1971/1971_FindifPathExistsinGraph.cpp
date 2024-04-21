#include "../inc.h"

class Solution {
   public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {}
};

void test(int n, vector<vector<int>>&& edges, int source, int destination, bool expect) {
    save4print(n, edges, source, destination);
    assert_eq_ret(expect, Solution().validPath(n, edges, source, destination));
}

int main() {
    test(3, {{0, 1}, {1, 2}, {2, 0}}, 0, 2, true);
    test(6, {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}}, 0, 5, false);
    return 0;
}
