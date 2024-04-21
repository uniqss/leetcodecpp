#include "../inc.h"

/*
time complexity: O(mn)
space complexity: O(1)
*/
class Solution {
   public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ret;
        int m = land.size(), n = land[0].size(), r1, c1, r2, c2, r, c;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == 1) {
                    r1 = i, c1 = j, r2 = i, c2 = j;
                    while (r2 < m - 1 && land[r2 + 1][j] == 1) ++r2;
                    while (c2 < n - 1 && land[r2][c2 + 1] == 1) ++c2;
                    ret.push_back({r1, c1, r2, c2});
                    for (r = r1; r <= r2; ++r) {
                        for (c = c1; c <= c2; ++c) {
                            land[r][c] = 0;
                        }
                    }
                }
            }
        }
        return ret;
    }
};

void test(vector<vector<int>>&& land, vector<vector<int>>&& expect) {
    sort(expect.begin(), expect.end());
    auto ret = Solution().findFarmland(land);
    sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test({{1, 0, 0}, {0, 1, 1}, {0, 1, 1}}, {{0, 0, 0, 0}, {1, 1, 2, 2}});
    test({{1, 1}, {1, 1}}, {{0, 0, 1, 1}});
    test({{0}}, {});
    return 0;
}
