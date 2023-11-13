#include "../inc.h"

// 中文官方 dfs
class Solution {
   public:
    vector<vector<int>> ret;
    vector<int> temp;
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ret;
    }
    void dfs(int curr, int n, int k) {
        if (temp.size() + (n - curr + 1) < k) {
            return;
        }
        if (temp.size() == k) {
            ret.emplace_back(temp);
            return;
        }
        temp.emplace_back(curr);
        dfs(curr + 1, n, k);
        temp.pop_back();
        dfs(curr + 1, n, k);
    }
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
