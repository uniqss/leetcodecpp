#include "../inc.h"

// 这个做法可以，但是会超时，必须优化
class Solution {
   public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> ret(queries.size(), false);
        for (size_t i = 0; i < queries.size(); i++) {
            const auto& query = queries[i];
            int start = query[0];
            int end = query[1];
            int count = query[2];
            int same = 0;
            int dict[26] = {0};
            for (int j = start; j <= end; j++) {
                auto& d = dict[s[j] - 'a'];
                ++d;
                if (d > 1 && d % 2 == 0) ++same;
                if (same + count >= (end - start + 1) / 2) {
                    ret[i] = true;
                    break;
                }
            }
        }

        return ret;
    }
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
