#include "../stl.h"

// 中文官方字典序法
class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> temp;
        for (int i = 1; i <= k; ++i) {
            temp.emplace_back(i);
        }
        temp.emplace_back(n + 1);

        int j = 0;
        while (j < k) {
            ret.emplace_back(temp.begin(), temp.begin() + k);
            j = 0;
            while (j < k && temp[j] + 1 == temp[j + 1]) {
                temp[j] = j + 1;
                ++j;
            }
            ++temp[j];
        }
        return ret;
    }
};

void test(int n, int k, vector<vector<int>>&& expect) {
    Solution s;
    auto ret = s.combine(n, k);
    auto ret_sorted = ret;
    auto expect_sorted = expect;
    sortvvrawInnerAndOuter(ret_sorted);
    sortvvrawInnerAndOuter(expect_sorted);
    if (ret_sorted == expect_sorted) {
        praw("ok.");
    } else {
        praw("not ok.");
        praw(n);
        praw(k);
        pvvraw(expect);
        pvvraw(ret);
    }
    pnewline();
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
