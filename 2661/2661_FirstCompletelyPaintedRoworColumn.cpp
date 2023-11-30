#include "../inc.h"

class Solution {
   public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {}
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
