#include "../inc.h"

struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return std::hash<size_t>()(p.first) ^ std::hash<size_t>()(p.second);
    }
};

class Solution {
   public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // -2:left   -1:right  [1, 9]:forward
        int posx = 0, posy = 0;
        int direction = 0;  // 0:north 1:west 2:south 3:east
        vector<int> absx = {0, 1, 0, -1};
        vector<int> absy = {1, 0, -1, 0};
        int ret = 0;
        unordered_set<pair<int, int>, PairHash> obstaclesSet;
        for (auto obstacle : obstacles) {
            obstaclesSet.insert({obstacle[0], obstacle[1]});
        }

        for (int command : commands) {
            if (command == -2) {
                direction = (direction + 3) % 4;
            } else if (command == -1) {
                direction = (direction + 1) % 4;
            } else {
                for (int i = 0; i < command; ++i) {
                    int tox = posx + absx[direction];
                    int toy = posy + absy[direction];
                    if (obstaclesSet.count({tox, toy}) > 0) break;
                    posx = tox;
                    posy = toy;
                    ret = max(posx * posx + posy * posy, ret);
                }
            }
        }
        return ret;
    }
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
