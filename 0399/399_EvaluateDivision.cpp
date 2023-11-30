#include "../inc.h"

class Solution {
   public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {}
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
