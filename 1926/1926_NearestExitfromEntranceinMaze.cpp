#include "../inc.h"

class Solution {
   public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {}
};

void test(vector<vector<char>>&& maze, vector<int>&& entrance, int expect) {
    save4print(maze, entrance);
    assert_eq_ret(expect, Solution().nearestExit(maze, entrance));
}

int main() {
    test({{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}}, {1, 2}, 1);
    test({{'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}}, {1, 0}, 2);
    test({{'.', '+'}}, {0, 0}, -1);
    return 0;
}
