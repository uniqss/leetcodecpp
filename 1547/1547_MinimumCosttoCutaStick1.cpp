#include "../inc.h"

/*
60
 29 30 40 50
30:
60 + 30 + 30 + 20
29:
60 + 31 + 11 + 20
40:
60 + 40 + 11 + 20
在偷看了这个题的标签是dp以后，瞬间觉得自己能搞定，燃鹅比想像的要复杂

又仔细想了一下，要动规其实要换思路，想像成有很多根短木棍，这个时候如果起点是a终点是b，再在后面拼了一段c，c的内部算法先不考虑
ab段的算法而言，一定有个最优解。那么动规就动起来了，是不是
*/
class Solution {
    int dp[102][102];

   public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        memset(dp, -1, sizeof(dp));
        return helper(cuts, 0, cuts.size() - 1);
    }
    int helper(const vector<int>& cuts, int lidx, int ridx) {
        if (ridx - lidx <= 1) return 0;
        if (dp[lidx][ridx] != -1) return dp[lidx][ridx];
        int cost = INT_MAX;
        for (int i = lidx + 1; i <= ridx - 1; i++) {
            int left_cost = helper(cuts, lidx, i);
            int right_cost = helper(cuts, i, ridx);
            int curr_cost = cuts[ridx] - cuts[lidx] + left_cost + right_cost;
            cost = min(cost, curr_cost);
        }
        dp[lidx][ridx] = cost;
        return cost;
    }
};

void test(int n, vector<int>&& cuts, int expect) {
    save4print(n, cuts);
    assert_eq_ret(expect, Solution().minCost(n, cuts));
}

int main() {
    test(7, {1, 3, 4, 5}, 16);
    test(9, {5, 6, 1, 4, 2}, 22);
    return 0;
}
