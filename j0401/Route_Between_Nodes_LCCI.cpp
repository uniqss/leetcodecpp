#include "../inc.h"

class Solution {
   public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {}
};

void test(int n, vector<vector<int>>&& graph, int start, int target, bool expect) {
    save4print(n, graph, start, target);
    assert_eq_ret(expect, Solution().findWhetherExistsPath(n, graph, start, target));
}

int main() {
    test(25, {{0, 1}, {1, 12}}, 0, 12, true);
    test(3, {{0, 1}, {0, 2}, {1, 2}, {1, 2}}, 0, 2, true);
    test(5, {{0, 1}, {0, 2}, {0, 4}, {0, 4}, {0, 1}, {1, 3}, {1, 4}, {1, 3}, {2, 3}, {3, 4}}, 0, 4,
         true);
    test(25, {{0, 1},  {0, 3},   {0, 10},  {0, 18},  {1, 2},   {1, 7},   {1, 11},  {1, 12}, {2, 4},
              {2, 5},  {2, 13},  {2, 16},  {3, 6},   {3, 8},   {4, 9},   {5, 17},  {7, 20}, {7, 22},
              {8, 10}, {10, 19}, {11, 15}, {13, 14}, {14, 21}, {15, 23}, {19, 24}, {20, 22}},
         0, 12, true);

    return 0;
}
