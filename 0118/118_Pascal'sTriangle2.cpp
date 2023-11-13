#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i) {
            ret[i].resize(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }

        return ret;
    }
};

void test(int numRows, const vector<vector<int>>& expect) {
    save4print(numRows);
    assert_eq_ret(expect, Solution().generate(numRows));
}

int main() {
    test(5, {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}});
    test(1, {{1}});
    return 0;
}
