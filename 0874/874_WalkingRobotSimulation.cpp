#include "../inc.h"

class Solution {
   public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {}
};

void test(vector<int>&& commands, vector<vector<int>>&& obstacles, int expect) {
    auto commands_param = commands;
    auto obstacles_param = obstacles;
    Solution so;
    auto ret = so.robotSim(commands, obstacles);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(commands_param);
        print(obstacles_param);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({4, -1, 3}, {}, 25);
    test({4, -1, 4, -2, 4}, {{2, 4}}, 65);
    test({6, -1, -1, 6}, {}, 36);
    return 0;
}
