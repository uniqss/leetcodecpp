#include "../inc.h"

class Solution {
   public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph_in(n), graph_out(n);
        int ret = 0;
        for (auto c : connections) graph_in[c[1]].push_back(c[0]), graph_out[c[0]].push_back(c[1]);
        vector<bool> vis(n);

        vis[0] = true;
        dfs(graph_in, graph_out, vis, ret, 0);

        return ret;
    }
    void dfs(vector<vector<int>>& graph_in, vector<vector<int>>& graph_out, vector<bool>& vis, int& ret, int curr) {
        for (int i : graph_in[curr]) {
            if (!vis[i]) {
                vis[i] = true;
                dfs(graph_in, graph_out, vis, ret, i);
            }
        }
        for (int i : graph_out[curr]) {
            if (!vis[i]) {
                vis[i] = true;
                ++ret;
                dfs(graph_in, graph_out, vis, ret, i);
            }
        }
    }
};

void test(int n, vector<vector<int>>&& connections, int expect) {
    save4print(n, connections);
    assert_eq_ret(expect, Solution().minReorder(n, connections));
}

int main() {
    test(6, {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}}, 3);
    test(5, {{1, 0}, {1, 2}, {3, 2}, {3, 4}}, 2);
    test(3, {{1, 0}, {2, 0}}, 0);

    return 0;
}
