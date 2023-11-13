#include "../inc.h"

class Solution {
   public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {}
};

void test(vector<vector<char>>&& maze, vector<int>&& entrance, int expect) {
    auto m_param = maze;
    auto e_param = entrance;
    Solution so;
    auto ret = so.nearestExit(maze, entrance);
    assert_eq_ret(expect, ret);
    print(m_param);
    print(e_param);
}

int main() {
    test({{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}}, {1, 2}, 1);
    test({{'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}}, {1, 0}, 2);
    test({{'.', '+'}}, {0, 0}, -1);
    return 0;
}
