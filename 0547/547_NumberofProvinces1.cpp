#include "../inc.h"

class Solution {
    vector<bool> vis;

   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ret = 0;
        vis.resize(isConnected.size());
        for (int i = 0; i < isConnected.size(); ++i) {
            if (dfs(isConnected, i)) ++ret;
        }
        return ret;
    }
    bool dfs(vector<vector<int>>& isConnected, int x) {
        if (vis[x]) return false;
        vis[x] = true;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (!vis[i] && isConnected[x][i]) dfs(isConnected, i);
        }
        return true;
    }
};

void test(vector<vector<int>>&& isConnected, int expect) {
    save4print(isConnected);
    assert_eq_ret(expect, Solution().findCircleNum(isConnected));
}

int main() {
    test({{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}}, 1);
    test({{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}, 2);
    test({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, 3);
    return 0;
}
