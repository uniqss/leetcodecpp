#include "../inc.h"

class Solution {
   public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price,
                          vector<vector<int>>& trips) {
        vector<vector<int>> tos(n);
        for (const auto& e : edges) tos[e[0]].emplace_back(e[1]), tos[e[1]].emplace_back(e[0]);
        vector<int> counts(n);
        function<bool(int, int, int)> dfs_count = [&](int parent, int curr, int end) -> bool {
            ++counts[curr];
            if (curr == end) return true;
            for (auto to : tos[curr]) {
                if (to == parent) continue;
                if (dfs_count(curr, to, end)) return true;
            }
            --counts[curr];
            return false;
        };
        for (const auto& t : trips) dfs_count(-1, t[0], t[1]);
        function<void(int, int, int, int&, int&)> dfs = [&](int parent, int curr, int vis,
                                                            int& half, int& nohalf) {
            if (counts[curr] > 0) {
                half += counts[curr] * price[curr] / 2;
                nohalf += counts[curr] * price[curr];
            }
            if (++vis == n) return;
            for (auto to : tos[curr]) {
                if (to == parent) continue;
                int tohalf = 0, tonohalf = 0;
                dfs(curr, to, vis, tohalf, tonohalf);
                half += tonohalf;
                nohalf += min(tohalf, tonohalf);
            }
        };
        int half = 0, nohalf = 0;
        dfs(-1, 0, 0, half, nohalf);
        return min(half, nohalf);
    }
};

void test(int n, vector<vector<int>>&& edges, vector<int>&& price, vector<vector<int>>&& trips,
          int expect) {
    save4print(n, edges, price, trips);
    assert_eq_ret(expect, Solution().minimumTotalPrice(n, edges, price, trips));
}

int main() {
    test(4, {{0, 1}, {1, 2}, {1, 3}}, {2, 2, 10, 6}, {{0, 3}, {2, 1}, {2, 3}}, 23);
    test(2, {{0, 1}}, {2, 2}, {{0, 0}}, 1);
    return 0;
}
