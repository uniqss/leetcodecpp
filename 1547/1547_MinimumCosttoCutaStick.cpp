#include "../inc.h"

class Solution {
    int dp[102][102];

   public:
    int minCost(int n, vector<int>& cuts) {
        std::sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        memset(dp, -1, sizeof(dp));
        return helper(cuts, 0, cuts.size() - 1);
    }
    int helper(const vector<int>& cuts, int l, int r) {
        if (l + 1 >= r) return 0;
        if (dp[l][r] > 0) return dp[l][r];
        int cost = INT_MAX;
        for (int i = l + 1; i <= r - 1; i++) {
            int curr_cost = helper(cuts, l, i) + helper(cuts, i, r) + cuts[r] - cuts[l];
            cost = min(cost, curr_cost);
        }
        dp[l][r] = cost;
        return cost;
    }
};

void test(int n, vector<int>&& cuts, int expect) {
    Solution so;
    auto ret = so.minCost(n, cuts);
    auto cuts_param = cuts;
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(n);
        print(cuts_param);
        print(expect);
        print(ret);
    }
}

int main() {
    test(30, {13,25,16,20,26,5,27,8,23,14,6,15,21,24,29,1,19,9,3}, 127);
    test(7, {1, 3, 4, 5}, 16);
    test(9, {5, 6, 1, 4, 2}, 22);
    return 0;
}
