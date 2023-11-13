#include "../inc.h"

class Solution {
   public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        int qsize = queries.size(), esize = equations.size();
        vector<double> ret(qsize, (double)-1.0);
        unordered_map<string, unordered_map<string, double>> dict;
        unordered_set<string> exists;
        for (int i = 0; i < esize; ++i) {
            const auto& eq = equations[i];
            dict[eq[0]][eq[1]] = values[i];
            dict[eq[1]][eq[0]] = (double)1.0 / values[i];
            exists.insert(eq[0]);
            exists.insert(eq[1]);
        }
        for (int i = 0; i < qsize; ++i) {
            if (exists.count(queries[i][0]) == 0 || exists.count(queries[i][1]) == 0) continue;
            queue<pair<string, double>> q;
            unordered_set<string> visited;
            q.emplace(queries[i][0], (double)1.0);
            visited.insert(queries[i][0]);
            while (!q.empty()) {
                auto [curr, val] = q.front();
                q.pop();
                if (curr == queries[i][1]) {
                    ret[i] = val;
                    break;
                }
                for (auto it : dict[curr]) {
                    if (visited.count(it.first) == 0) {
                        visited.insert(it.first);
                        q.emplace(it.first, val * it.second);
                    }
                }
            }
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
    test({{"a", "b"}, {"b", "c"}}, {2.0, 3.0}, {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}},
         {6.00000, 0.50000, -1.00000, 1.00000, -1.00000});
    test({{"a", "b"}, {"b", "c"}, {"bc", "cd"}}, {1.5, 2.5, 5.0}, {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}},
         {3.75000, 0.40000, 5.00000, 0.20000});
    test({{"a", "b"}}, {0.5}, {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}}, {0.50000, 2.00000, -1.00000, -1.00000});
    return 0;
}
