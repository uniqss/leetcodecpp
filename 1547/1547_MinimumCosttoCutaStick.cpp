#include "../inc.h"

class Solution {
    int dp[102][102];

   public:
    int minCost(int n, vector<int>& cuts) {}
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
    test(7, {1, 3, 4, 5}, 16);
    test(9, {5, 6, 1, 4, 2}, 22);
    return 0;
}
