#include "../inc.h"

class Solution {
   public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {}
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
    test({{"x1", "x2"}, {"x2", "x3"}, {"x1", "x4"}, {"x2", "x5"}}, {3.0, 0.5, 3.4, 5.6},
         {{"x2", "x4"},
          {"x1", "x5"},
          {"x1", "x3"},
          {"x5", "x5"},
          {"x5", "x1"},
          {"x3", "x4"},
          {"x4", "x3"},
          {"x6", "x6"},
          {"x0", "x0"}},
         {1.13333, 16.8, 1.5, 1.0, 0.05952, 2.26667, 0.44118, -1.0, -1.0});
    test({{"a", "c"}, {"b", "e"}, {"c", "d"}, {"e", "d"}}, {2.0, 3.0, 0.5, 5.0}, {{"a", "b"}}, {0.06667});
    test({{"a", "b"}, {"b", "c"}}, {2.0, 3.0}, {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}},
         {6.00000, 0.50000, -1.00000, 1.00000, -1.00000});
    test({{"a", "b"}, {"b", "c"}, {"bc", "cd"}}, {1.5, 2.5, 5.0}, {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}},
         {3.75000, 0.40000, 5.00000, 0.20000});
    test({{"a", "b"}}, {0.5}, {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}}, {0.50000, 2.00000, -1.00000, -1.00000});
    return 0;
}
