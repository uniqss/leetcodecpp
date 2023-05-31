#include "../inc.h"

/*
依然可以证明，它是一棵两层叶节点的二叉树，无兄弟叶节点可以分布在上一层的任何位置
*/
class Solution {
    int dp[40][40];
    int vmax[40][40];

   public:
    int mctFromLeafValues(vector<int>& arr) {
        memset(dp, 0, sizeof(dp));
        memset(vmax, 0, sizeof(vmax));
        return helper(arr, 0, arr.size() - 1);
    }
    int getmax(vector<int>& arr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == r) return arr[l];
        if (vmax[l][r] > 0) return vmax[l][r];
        int val = arr[l];
        for (int i = l + 1; i <= r; i++) {
            val = max(val, arr[i]);
        }

        vmax[l][r] = val;

        return val;
    }
    int helper(vector<int>& arr, int l, int r) {
        if (l >= r) return 0;
        if (dp[l][r] > 0) return dp[l][r];
        int val = INT_MAX, curr = 0;
        if (l + 1 == r) {
            val = arr[l] * arr[r];
        }
        for (int i = l; i < r; i++) {
            curr = helper(arr, l, i) + helper(arr, i + 1, r) + getmax(arr, l, i) * getmax(arr, i + 1, r);
            val = min(val, curr);
        }
        dp[l][r] = val;
        return val;
    }
};

void test(vector<int>&& arr, int expect) {
    Solution so;
    auto arr_param = arr;
    auto ret = so.mctFromLeafValues(arr);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(arr_param);
        print(expect);
        print(ret);
    }
}

int main() {
    test({12, 4, 13, 8,  10, 1,  5, 14, 5,  4, 3, 11, 6, 7,  5,  12, 6, 4, 14, 15,
          2,  2, 11, 13, 10, 15, 3, 11, 15, 1, 2, 10, 6, 14, 15, 9,  7, 9, 9,  5},
         3898);
    test({6, 2, 4}, 32);
    test({4, 11}, 44);
    test({7, 12, 8, 10}, 284);
    return 0;
}
