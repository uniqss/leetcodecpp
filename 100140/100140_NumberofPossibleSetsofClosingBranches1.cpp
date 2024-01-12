#include "../inc.h"

/*
总结：这题暴露了，backtrack没学到家。当时一直在backtrack的思路里出不来。没有看透bt的本质
图状结构有重复连接的情况，用vis进行dfs是可以的，但是，如果我们要对每个节点进行两种不同状态的全枚举
就不应该在这个泥潭里一直深陷，就应该立刻想到2^n的递增解法。总共n个点，每个都可选可不选，居然在那btbtbt
4,2 6,1 3 5 7 如果有横连， vis在进到1时如果退出来必须不还原，以规避3横串到1。另一方面，退出2时如果不还原，
改变4状态后2就进不来了。所以这是个死锁。
*/
class Solution {
   public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<unordered_map<int, int>> todis(n);
        for (const auto& r : roads) {
            int a = r[0], b = r[1], dis = r[2];
            if (todis[a].count(b) > 0)
                todis[a][b] = min(dis, todis[a][b]);
            else
                todis[a][b] = dis;
            if (todis[b].count(a) > 0)
                todis[b][a] = min(dis, todis[b][a]);
            else
                todis[b][a] = dis;
        }
        vector<bool> closed(n);
        auto next = [&]() {
            for (int i = n - 1; i >= 0; --i) {
                if (!closed[i]) {
                    closed[i] = true;
                    for (int j = i + 1; j < n; ++j) closed[j] = false;
                    return true;
                }
            }
            return false;
        };
        function<bool(int, int, int, vector<bool>&)> dfs = [&](int curr, int end, int dis, vector<bool>& vis) -> bool {
            for (auto [to, todis] : todis[curr]) {
                if (closed[to]) continue;
                if (vis[to]) continue;
                vis[to] = true;
                if (dis + todis <= maxDistance) {
                    if (to == end) {
                        return true;
                    }
                    if (dfs(to, end, dis + todis, vis)) return true;
                }
                vis[to] = false;
            }
            return false;
        };
        auto valid = [&]() {
            for (int i = 0; i < n; ++i) {
                if (closed[i]) continue;
                for (int j = i + 1; j < n; ++j) {
                    if (closed[j]) continue;
                    vector<bool> vis(n);
                    vis[i] = true;
                    if (!dfs(i, j, 0, vis)) return false;
                }
            }
            return true;
        };
        int ret = 0;
        while (true) {
            if (valid()) ++ret;
            if (!next()) break;
        }
        return ret;
    }
};

void test(int n, int maxDistance, vector<vector<int>>&& roads, int expect) {
    save4print(n, maxDistance, roads);
    assert_eq_ret(expect, Solution().numberOfSets(n, maxDistance, roads));
}

int main() {
    test(3, 5, {{0, 1, 2}, {1, 2, 10}, {0, 2, 10}}, 5);
    test(3, 5, {{0, 1, 20}, {0, 1, 10}, {1, 2, 2}, {0, 2, 2}}, 7);
    test(1, 10, {}, 2);
    return 0;
}
