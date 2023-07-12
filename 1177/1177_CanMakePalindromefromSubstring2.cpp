#include "../inc.h"

/*
卧槽这么神奇的算法为什么我想不出来。。。。。。所有数都是a-z，数组非常大，我们要取的是任意起点到任意终点算中间不配对的数量
直接统计起始至当前的所有a-z的数量，那么就可以任意两点间互相减出不配对的数量了
*/
class Solution {
   public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> ret(queries.size(), false);
        vector<vector<int>> dict(s.size() + 1, vector<int>(26, 0));
        for (int i = 0; i < s.size(); i++) {
            dict[i + 1] = dict[i];
            ++dict[i + 1][s[i] - 'a'];
        }
        for (int i = 0; i < queries.size(); i++) {
            int same = 0;
            int start = queries[i][0];
            int end = queries[i][1];
            int count = queries[i][2];
            for (int j = 0; j < 26; j++) {
                same += (dict[end + 1][j] - dict[start][j]) / 2;
            }
            if (same + count >= (end - start + 1) / 2) ret[i] = true;
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
