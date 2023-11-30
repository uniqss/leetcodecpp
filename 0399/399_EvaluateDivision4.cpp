#include "../inc.h"

class Solution {
   public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> dict;
        int esize = equations.size(), qsize = queries.size();
        for (int i = 0; i < esize; ++i) {
            const auto &a = equations[i][0], &b = equations[i][1];
            dict[a][b] = values[i];
            dict[b][a] = 1.0 / values[i];
        }
        vector<double> ret(qsize, -1.0);
        for (int i = 0; i < qsize; ++i) {
            const auto &a = queries[i][0], &b = queries[i][1];
            if (dict.count(a) == 0 || dict.count(b) == 0) continue;
            double curr = 1.0;
            unordered_set<string> vis;
            if (dfs(dict, a, b, curr, vis)) ret[i] = curr;
        }
        return ret;
    }
    bool dfs(unordered_map<string, unordered_map<string, double>>& dict, const string& a, const string& b, double& curr,
             unordered_set<string>& vis) {
        if (dict[a].count(b) > 0) {
            curr *= dict[a][b];
            return true;
        }
        for (const auto& [c, ac] : dict[a]) {
            double ab = ac;
            if (vis.count(c) > 0) continue;
            vis.insert(c);
            if (dfs(dict, c, b, ab, vis)) {
                curr *= ab;
                return true;
            }
        }
        return false;
    }
};

void test(vector<vector<string>>&& equations, vector<double>&& values, vector<vector<string>>&& queries,
          const vector<double>& expect) {
    save4print(equations, values, queries);
    assert_eq_ret(expect, Solution().calcEquation(equations, values, queries));
}

int main() {
    test({{"x1", "x2"}, {"x2", "x3"}, {"x3", "x4"}, {"x4", "x5"}}, {3.0, 4.0, 5.0, 6.0},
         {{"x1", "x5"}, {"x5", "x2"}, {"x2", "x4"}, {"x2", "x2"}, {"x2", "x9"}, {"x9", "x9"}},
         {360, 0.00833333, 20, 1, -1, -1});
    test({{"a", "c"}, {"b", "e"}, {"c", "d"}, {"e", "d"}}, {2.0, 3.0, 0.5, 5.0}, {{"a", "b"}}, {0.06667});
    test({{"a", "b"}, {"b", "c"}}, {2.0, 3.0}, {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}},
         {6.00000, 0.50000, -1.00000, 1.00000, -1.00000});
    test({{"a", "b"}, {"b", "c"}, {"bc", "cd"}}, {1.5, 2.5, 5.0}, {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}},
         {3.75000, 0.40000, 5.00000, 0.20000});
    test({{"a", "b"}}, {0.5}, {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}}, {0.50000, 2.00000, -1.00000, -1.00000});
    return 0;
}
