#include "../inc.h"

class Solution {
   public:
    int findf(vector<int>& f, vector<double>& w, int x) {
        if (f[x] != x) {
            int fx = findf(f, w, f[x]);
            w[x] = w[x] * w[f[x]];
            f[x] = fx;
        }
        return f[x];
    }
    void merge(vector<int>& f, vector<double>& w, int x, int y, double val) {
        int fx = findf(f, w, x), fy = findf(f, w, y);
        f[fx] = fy;
        w[fx] = val * w[y] / w[x];
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        int nvars = 0;
        unordered_map<string, int> variables;
        int n = equations.size(), retsize = queries.size();
        for (const auto& e : equations) {
            if (variables.count(e[0]) == 0) variables[e[0]] = nvars++;
            if (variables.count(e[1]) == 0) variables[e[1]] = nvars++;
        }
        vector<int> f(nvars);
        vector<double> w(nvars, 1.0);
        for (int i = 0; i < nvars; ++i) {
            f[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            int ia = variables[equations[i][0]], ib = variables[equations[i][1]];
            merge(f, w, ia, ib, values[i]);
        }
        vector<double> ret(retsize, -1.0);
        for (int i = 0; i < retsize; ++i) {
            const auto &sa = queries[i][0], &sb = queries[i][1];
            if (variables.count(sa) == 0 || variables.count(sb) == 0) continue;
            int ia = variables[sa], ib = variables[sb];
            int fa = findf(f, w, ia), fb = findf(f, w, ib);
            if (fa != fb) continue;
            ret[i] = w[ia] / w[ib];
        }

        return ret;
    }
};

void test(vector<vector<string>>&& equations, vector<double>&& values, vector<vector<string>>&& queries,
          const vector<double>& expect) {
    save4print(equations);
    save4print(values);
    save4print(queries);
    auto ret = Solution().calcEquation(equations, values, queries);
    assert_eq_ret(expect, ret);
}

int main() {
    test({{"a", "c"}, {"b", "e"}, {"c", "d"}, {"e", "d"}}, {2.0, 3.0, 0.5, 5.0}, {{"a", "b"}}, {0.06667});
    test({{"a", "b"}, {"b", "c"}}, {2.0, 3.0}, {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}},
         {6.00000, 0.50000, -1.00000, 1.00000, -1.00000});
    test({{"a", "b"}, {"b", "c"}, {"bc", "cd"}}, {1.5, 2.5, 5.0}, {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}},
         {3.75000, 0.40000, 5.00000, 0.20000});
    test({{"a", "b"}}, {0.5}, {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}}, {0.50000, 2.00000, -1.00000, -1.00000});
    return 0;
}
