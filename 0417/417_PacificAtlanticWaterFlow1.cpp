#include "../inc.h"

struct SimplePairHasher {
    size_t operator()(const std::pair<int, int>& pv) const {
        return std::hash<int>()(pv.first) ^ std::hash<int>()(pv.second);
    }
};
class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        unordered_set<pair<int, int>, SimplePairHasher> retdict;
        vector<vector<int>> ret;
        int m = heights.size(), n = heights[0].size();
        if (m == 1 || n == 1) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    ret.push_back({i, j});
                }
            }
            return ret;
        }
        vector<vector<int>> dict(m, vector<int>(n));
        queue<pair<int, int>> q1, q2;
        for (int i = 0; i < m; ++i) q1.emplace(i, 0), q2.emplace(i, n - 1);
        for (int j = 0; j < n; ++j) q1.emplace(0, j), q2.emplace(m - 1, j);
        while (!q1.empty()) {
            auto [x, y] = q1.front();
            q1.pop();
            dict[x][y] |= 1;
            if (dict[x][y] == 3 && retdict.count({x, y}) == 0) retdict.emplace(x, y), ret.push_back({x, y});
            int height = heights[x][y];
            checkset(x + 1, y, height, heights, dict, q1, 2);
            checkset(x - 1, y, height, heights, dict, q1, 2);
            checkset(x, y + 1, height, heights, dict, q1, 2);
            checkset(x, y - 1, height, heights, dict, q1, 2);
        }
        while (!q2.empty()) {
            auto [x, y] = q2.front();
            q2.pop();
            dict[x][y] |= 2;
            if (dict[x][y] == 3 && retdict.count({x, y}) == 0) retdict.emplace(x, y), ret.push_back({x, y});
            int height = heights[x][y];
            checkset(x + 1, y, height, heights, dict, q2, 1);
            checkset(x - 1, y, height, heights, dict, q2, 1);
            checkset(x, y + 1, height, heights, dict, q2, 1);
            checkset(x, y - 1, height, heights, dict, q2, 1);
        }
        return ret;
    }
    void checkset(int x, int y, int height, const vector<vector<int>>& heights, vector<vector<int>>& dict,
                  queue<pair<int, int>>& q, int v) {
        int m = dict.size(), n = dict[0].size();
        if (x < 0 || x >= m) return;
        if (y < 0 || y >= n) return;
        if (heights[x][y] < height) return;
        if (dict[x][y] == 0 || dict[x][y] == v) {
            q.emplace(x, y);
        }
    }
};

void test(vector<vector<int>>&& heights, const vector<vector<int>>& cexpect) {
    auto expect = cexpect;
    auto p1 = heights;
    Solution so;
    auto ret = so.pacificAtlantic(heights);
    sort(expect.begin(), expect.end());
    sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
    print(p1);
}

int main() {
    test({{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}},
         {{0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}});
    test({{1}}, {{0, 0}});

    return 0;
}
