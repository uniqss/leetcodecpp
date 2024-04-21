#include "../inc.h"

/*
time complexity: O(n)
space complexity: O(n)
*/
class Solution {
   public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> outs;
        for (const auto& edge : edges) {
            int ui = edge[0], vi = edge[1];
            outs[ui].emplace_back(vi);
            outs[vi].emplace_back(ui);
        }
        vector<int> vis(n + 1);
        function<bool(int, int)> dfs = [&](int from, int to) -> bool {
            if (from == to) return true;
            if (vis[from]) return false;
            vis[from] = true;
            for (int o : outs[from]) {
                if (dfs(o, to)) return true;
            }
            return false;
        };
        return dfs(source, destination);
    }
};

void test(int n, vector<vector<int>>&& edges, int source, int destination, bool expect) {
    save4print(n, edges, source, destination);
    assert_eq_ret(expect, Solution().validPath(n, edges, source, destination));
}

int main() {
    test(3, {{0, 1}, {1, 2}, {2, 0}}, 0, 2, true);
    test(6, {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}}, 0, 5, false);
    return 0;
}
