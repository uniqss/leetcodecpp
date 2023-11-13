#include "../inc.h"

class Solution {
   public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {}
};

void test(vector<int>&& commands, vector<vector<int>>&& obstacles, int expect) {
    save4print(commands, obstacles);
    assert_eq_ret(expect, Solution().robotSim(commands, obstacles));
}

int main() {
    test({4, -1, 3}, {}, 25);
    test({4, -1, 4, -2, 4}, {{2, 4}}, 65);
    test({6, -1, -1, 6}, {}, 36);
    return 0;
}
