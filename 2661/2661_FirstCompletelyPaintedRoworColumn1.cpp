#include "../inc.h"

// 1空间相像力  2细节(1-indexed)
class Solution {
   public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int asize = arr.size(), m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> n2xy(m * n);
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                n2xy[mat[x][y] - 1] = {x, y};
            }
        }
        vector<int> sumx(m), sumy(n);
        for (int i = 0; i < asize; ++i) {
            auto& xy = n2xy[arr[i] - 1];
            int x = xy.first, y = xy.second;
            if (++sumx[x] == n) return i;
            if (++sumy[y] == m) return i;
        }
        return -1;
    }
};

void test(vector<int>&& arr, vector<vector<int>>&& mat, int expect) {
    save4print(arr, mat);
    assert_eq_ret(expect, Solution().firstCompleteIndex(arr, mat));
}

int main() {
    test({1, 3, 4, 2}, {{1, 4}, {2, 3}}, 2);
    test({2, 8, 7, 4, 1, 3, 5, 6, 9}, {{3, 2, 5}, {1, 4, 6}, {8, 7, 9}}, 3);
    return 0;
}
