#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> data;

        backtrace(ret, n, k, data, 0);
        return ret;
    }
    void backtrace(vector<vector<int>>& ret, int n, int k, vector<int>& data, int curr) {}
};

void test(int n, int k, vector<vector<int>>&& expect) {
    Solution s;
    auto ret = s.combine(n, k);
    auto ret_sorted = ret;
    auto expect_sorted = expect;
    sortvvrawInnerAndOuter(ret_sorted);
    sortvvrawInnerAndOuter(expect_sorted);
    if (ret_sorted == expect_sorted) {
        print("ok.");
    } else {
        print("not ok.");
        print(n);
        print(k);
        print(expect);
        print(ret);
    }
    print();
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
