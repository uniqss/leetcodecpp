#include "../inc.h"

class Solution {
   public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n);
        int ret = 0;
        queue<int> q;
        vector<vector<int>> dict_to(n), dict_from(n);
        for (auto it : connections) dict_to[it[1]].push_back(it[0]), dict_from[it[0]].push_back(it[1]);
        q.emplace(0);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            vis[curr] = true;
            for (auto it : dict_to[curr]) {
                if (!vis[it]) q.push(it);
            }
            for (auto it : dict_from[curr]) {
                if (!vis[it]) {
                    ++ret;
                    q.push(it);
                }
            }
        }

        return ret;
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
