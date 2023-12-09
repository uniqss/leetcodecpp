#include "../inc.h"

class Solution {
   public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        /*
        思路整理：
        虽然不是一棵树，但是把这个无向图放在桌子上，相像它们是一根根线连接的点。抓住其中任意一个点，把它提起来。
        如果两点间线的长度相等的话，则会形成一棵多叉树，一层一层。要做的是bfs让每层可打折可不打折。
        half(n) = count(n) * price(n) / 2 + nohalf(n + 1)
        nohalf(n) = count(n) + min(half(n + 1), nohalf(n + 1))
        最终取到的根节点half(1)/nohalf(1) 的最小值，就是要的值
        中间需要先想办法统计一下所有点的数量，不过的点记为0，要乘进v(n)里面去。因为n个点n-1条线，路径是唯一的
        */
        vector<vector<int>> tos(n);
        for (const auto& e : edges) tos[e[0]].emplace_back(e[1]), tos[e[1]].emplace_back(e[0]);
        vector<int> counts(n);
        function<bool(int, int, int)> dfs_count = [&](int parent, int curr, int end) {
            ++counts[curr];
            if (curr == end) return true;
            for (const auto& to : tos[curr]) {
                if (to == parent) continue;
                if (dfs_count(curr, to, end)) return true;
            }
            --counts[curr];
            return false;
        };
        for (const auto& trip : trips) dfs_count(-1, trip[0], trip[1]);
        function<void(int, int, int&, int&)> dfs = [&](int parent, int curr, int& half, int& nohalf) {
            int next_half = 0, next_nohalf = 0;
            for (const auto& to : tos[curr]) {
                if (to == parent) continue;
                int to_half = INT_MAX, to_nohalf = INT_MAX;
                dfs(curr, to, to_half, to_nohalf);
                if (to_half == INT_MAX && to_nohalf == INT_MAX) continue;
                next_half += min(to_half, to_nohalf);
                next_nohalf += to_nohalf;
            }
            half = counts[curr] * price[curr] / 2 + next_nohalf;
            nohalf = counts[curr] * price[curr] + min(next_half, next_nohalf);
        };
        int half = INT_MAX, nohalf = INT_MAX;
        dfs(-1, 0, half, nohalf);
        return min(half, nohalf);
    }
};

void test(int n, vector<vector<int>>&& edges, vector<int>&& price, vector<vector<int>>&& trips, int expect) {
    save4print(n, edges, price, trips);
    assert_eq_ret(expect, Solution().minimumTotalPrice(n, edges, price, trips));
}

int main() {
    test(4, {{0, 1}, {1, 2}, {1, 3}}, {2, 2, 10, 6}, {{0, 3}, {2, 1}, {2, 3}}, 23);
    test(2, {{0, 1}}, {2, 2}, {{0, 0}}, 1);
    return 0;
}
