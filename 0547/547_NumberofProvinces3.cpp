#include "../inc.h"

class Solution {
   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int dsize = isConnected.size(), ret = 0;
        vector<bool> vis(dsize);
        for (int i = 0; i < dsize; ++i) {
            if (!vis[i]) {
                ++ret;
                dfs(isConnected, vis, i);
            }
        }
        return ret;
    }
    void dfs(vector<vector<int>>& dict, vector<bool>& vis, int curr) {
        vis[curr] = true;
        for (int i = 0; i < dict.size(); ++i) {
            if (dict[i][curr] && !vis[i]) dfs(dict, vis, i);
        }
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
