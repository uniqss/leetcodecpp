#include "../inc.h"

class Solution {
   public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {}
};

void test(string s, vector<vector<int>>&& queries, const vector<bool>& expect) {
    Solution so;
    auto ret = so.canMakePaliQueries(s, queries);
    auto queries_param = queries;
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(s);
        print(queries_param);
        print(expect);
        print(ret);
    }
}

int main() {
    test("abcda", {{0, 4, 1}}, {true});
    test("hunu", {{0, 3, 1}}, {true});
    test("hunu",
         {{1, 1, 1},
          {2, 3, 0},
          {3, 3, 1},
          {0, 3, 2},
          {1, 3, 3},
          {2, 3, 1},
          {3, 3, 1},
          {0, 3, 0},
          {1, 1, 1},
          {2, 3, 0},
          {3, 3, 1},
          {0, 3, 1},
          {1, 1, 1}},
         {true, false, true, true, true, true, true, false, true, false, true, true, true});
    test("abcda", {{3, 3, 0}, {1, 2, 0}, {0, 3, 1}, {0, 3, 2}, {0, 4, 1}}, {true, false, false, true, true});
    test("lyb", {{0, 1, 0}, {2, 2, 1}}, {false, true});
    return 0;
}
