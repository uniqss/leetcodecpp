#include "../inc.h"

/*
time complexity: O(n^2)
space complexity: O(n)
*/
class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (edges.empty()) return {0};
        vector<int> ret;
        unordered_map<int, unordered_set<int>> tos;
        for (const auto& edge : edges) {
            tos[edge[1]].emplace(edge[0]);
            tos[edge[0]].emplace(edge[1]);
        }
        while (tos.size() > 2) {
            vector<pair<int, int>> leafs;
            for (const auto& [from, to] : tos) {
                if (to.size() == 1) leafs.push_back({from, *to.begin()});
            }
            for (auto [from, to] : leafs) {
                tos.erase(from);
                tos[to].erase(from);
            }
        }
        for (const auto& [from, _] : tos) ret.emplace_back(from);
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
