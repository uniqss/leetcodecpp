#include "../inc.h"

class Solution {
   public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {}
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