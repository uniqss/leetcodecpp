#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {}
};

void test(int n, int k, vector<vector<int>>&& expect) {
    auto ret = Solution().combine(n, k);
    sortvvrawInnerAndOuter(expect, ret);
    assert_eq_ret(expect, ret);
}

/*
1 <= n <= 20
1 <= k <= n
*/
int main() {
    test(4, 2,
         {
             {2, 4},
             {3, 4},
             {2, 3},
             {1, 2},
             {1, 3},
             {1, 4},
         });
    test(1, 1, {{1}});
    test(13, 13, {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}});
    return 0;
}

/*
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
