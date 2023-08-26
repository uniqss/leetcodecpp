#include "../inc.h"

class Solution {
   public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, int> variables;
        int nvars = 0;
        for (int i = 0; i < n; ++i) {
            const auto &va = equations[i][0], &vb = equations[i][1];
            if (variables.count(va) == 0) variables[va] = nvars++;
            if (variables.count(vb) == 0) variables[vb] = nvars++;
        }
        vector<vector<pair<int, double>>> dict(nvars);
        for (int i = 0; i < n; ++i) {
            int ia = variables[equations[i][0]], ib = variables[equations[i][1]];
            dict[ia].emplace_back(ib, values[i]);
            dict[ib].emplace_back(ia, 1.0 / values[i]);
        }
        vector<double> ret(queries.size(), -1);
        for (int i = 0; i < queries.size(); ++i) {
            const auto& q = queries[i];
            if (variables.count(q[0]) == 0 || variables.count(q[1]) == 0) continue;
            vector<double> vis(nvars, -1);
            int ia = variables[q[0]], ib = variables[q[1]];
            if (ia == ib) {
                ret[i] = 1;
                continue;
            }
            queue<int> qi;
            qi.emplace(ia);
            vis[ia] = 1.0;
            while (!qi.empty() && vis[ib] < 0) {
                int curr = qi.front();
                qi.pop();
                for (const auto& [next, val] : dict[curr]) {
                    if (vis[next] > 0) continue;
                    vis[next] = vis[curr] * val;
                    qi.emplace(next);
                }
            }
            ret[i] = vis[ib];
        }
        return ret;
    }
};

void test(vector<vector<string>>&& equations, vector<double>&& values, vector<vector<string>>&& queries,
          const vector<double>& expect) {
    auto e_param = equations;
    auto v_param = values;
    auto q_param = queries;
    Solution so;
    auto ret = so.calcEquation(equations, values, queries);
    assert_eq_ret(expect, ret);
    print(e_param);
    print(v_param);
    print(q_param);
}

int main() {
    test({{"a", "b"}, {"b", "c"}}, {2.0, 3.0}, {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}},
         {6.00000, 0.50000, -1.00000, 1.00000, -1.00000});
    test({{"a", "b"}, {"b", "c"}, {"bc", "cd"}}, {1.5, 2.5, 5.0}, {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}},
         {3.75000, 0.40000, 5.00000, 0.20000});
    test({{"a", "b"}}, {0.5}, {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}}, {0.50000, 2.00000, -1.00000, -1.00000});
    return 0;
}
