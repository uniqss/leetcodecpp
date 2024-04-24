#include "../inc.h"

class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (edges.empty()) return {0};
        vector<int> ret;
        unordered_map<int, unordered_set<int>> tos;
        std::size_t max_remain = 0;
        for (const auto& edge : edges) {
            int from = edge[0], to = edge[1];
            tos[from].emplace(to);
            max_remain = max(max_remain, tos[from].size());
            tos[to].emplace(from);
            max_remain = max(max_remain, tos[to].size());
        }
        while (max_remain > 1) {
            vector<int> dels;
            for (const auto& it : tos) {
                if (it.second.size() == 1) dels.emplace_back(it.first);
            }
            for (int d : dels) {
                int from = d, to = *tos[d].begin();
                tos.erase(from);
                tos[to].erase(from);
            }
            max_remain = 0;
            for (auto it = tos.begin(); it != tos.end(); ++it) {
                max_remain = max(max_remain, it->second.size());
            }
        }
        for (const auto& [from, to] : tos) ret.emplace_back(from);

        return ret;
    }
};

void test(int n, vector<vector<int>>&& edges, vector<int>&& expect) {
    save4print(n, edges);
    sort(expect.begin(), expect.end());
    auto ret = Solution().findMinHeightTrees(n, edges);
    sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test(4, {{1, 0}, {1, 2}, {1, 3}}, {1});
    test(6, {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}}, {3, 4});
    test(1, {}, {0});
    return 0;
}
