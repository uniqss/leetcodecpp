#include "../inc.h"

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
#define ALL(x) x.begin(), x.end()

// dijkstra 经典题
class Solution {
   public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source,
                                           int destination, int target) {
        vector<vector<int>> ret;
        vector<vector<int>> g(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) g[i][i] = 0;
        for (const auto& e : edges) {
            int a = e[0], b = e[1], wt = e[2];
            g[a][b] = min(g[a][b], wt);
            g[b][a] = min(g[b][a], wt);
        }

        vector<vector<int>> dis(2, vector<int>(n, INT_MAX));
        vector<vector<int>> from(2, vector<int>(n, source));
        auto dijkstra = [&](int didx) {
            vector<bool> vis(n, false);
            auto& d = dis[didx];
            d[source] = 0;
            for (int i = 0; i < n - 1; ++i) {
                int imin = -1;
                for (int j = 0; j < n; ++j) {
                    if (!vis[j] && d[j] < d[imin]) imin = j;
                }
                vis[imin] = true;
                for (int j = 0; j < n; ++j) {
                    int min2j = g[imin][j];
                    if (didx == 0 && min2j == -1) min2j = 1;
                    if (min2j == -1) continue;
                    if (d[imin] + min2j < d[j]) {
                        d[j] = d[imin] + min2j;
                        from[didx][j] = imin;
                    }
                }
            }
        };
        dijkstra(0);
        if (dis[0][destination] > target) return ret;
        if (dis[0][destination] == target) {  // 所有变1并返回
            ret = edges;
            for (auto& e : ret)
                if (e[2] == -1) e[2] = 1;
            return ret;
        }
        dijkstra(1);
        if (dis[1][target] < target) return ret;
        int remain = dis[1][target] - target;
        ret = edges;
        int curr = destination;
        unordered_set<int, int> dictchange;
        while (curr != source) {
            dictchange.insert(curr);
            curr = from[1][curr];
        }
        vector<pair<int, int>> pathnochange;
        curr = destination;
        int weight = 0;
        while (curr != source) {
            int currfrom = from[0][curr];
            weight += g[currfrom][curr];
            if (dictchange.count(currfrom) > 0) {
                pathnochange.push_back({curr, weight});
                weight = 0;
            }
            curr = from[0][curr];
        }

        while (true) {
            int fnochange = from[1][curr], fchange = from[0][curr];
            int wtnochange = g[fnochange][curr];
            while (fchange != fnochange) {
            }
        }

        return ret;
    }
};

void test(int n, vector<vector<int>>&& edges, int source, int destination, int target,
          const vector<vector<int>>& expect) {
    save4print(n, edges, source, destination, target);
    assert_eq_ret(expect, Solution().modifiedGraphEdges(n, edges, source, destination, target));
}

int main() {
    test(5, {{4, 1, -1}, {2, 0, -1}, {0, 3, -1}, {4, 3, -1}}, 0, 1, 5,
         {{4, 1, 1}, {2, 0, 1}, {0, 3, 3}, {4, 3, 1}});
    test(3, {{0, 1, -1}, {0, 2, 5}}, 0, 2, 6, {});
    test(4, {{1, 0, 4}, {1, 2, 3}, {2, 3, 5}, {0, 3, -1}}, 0, 2, 6,
         {{1, 0, 4}, {1, 2, 3}, {2, 3, 5}, {0, 3, 1}});
    return 0;
}
