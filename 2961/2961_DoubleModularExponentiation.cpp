#include "../inc.h"

typedef long long LL;
class Solution {
   public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {}
};

void test(vector<vector<int>>&& v, int target, const vector<int>& expect) {
    save4print(v, target);
    assert_eq_ret(expect, Solution().getGoodIndices(v, target));
}

int main() {
    test({{2, 2, 3, 2},
          {1, 3, 3, 2},
          {3, 2, 2, 3},
          {3, 1, 2, 3},
          {1, 2, 3, 1},
          {2, 2, 2, 2},
          {2, 1, 3, 1},
          {3, 2, 2, 2},
          {2, 1, 3, 1},
          {3, 3, 1, 3}},
         0, {0, 2, 3, 4, 5, 6, 8});
    test({{9, 2, 8, 5}, {7, 8, 8, 8}, {8, 9, 6, 1}, {8, 6, 2, 2}, {3, 6, 3, 1}}, 9, {});
    test({{39, 3, 1000, 1000}}, 17, {});
    test({{2, 3, 3, 10}, {3, 3, 3, 1}, {6, 1, 1, 4}}, 2, {0, 2});
    test({{39, 3, 1000, 1000}}, 17, {});
    return 0;
}
