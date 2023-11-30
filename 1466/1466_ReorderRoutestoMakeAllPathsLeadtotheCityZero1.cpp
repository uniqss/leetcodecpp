#include "../inc.h"

class Solution {
   public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n);
        vis[0] = true;
        int ret = 0;
        queue<int> q;
        unordered_map<int, unordered_set<int>> dict_to, dict_from;
        for (auto it : connections) dict_to[it[1]].insert(it[0]), dict_from[it[0]].insert(it[1]);
        for (auto it : dict_to[0]) q.push(it);
        for (auto it : dict_from[0]) {
            ++ret;
            q.push(it);
        }
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
