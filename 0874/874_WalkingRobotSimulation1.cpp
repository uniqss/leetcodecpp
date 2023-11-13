#include "../inc.h"

class hash_pair {
   public:
    size_t operator()(const pair<int, int>& val) const {
        return std::hash<int>()(val.first) + std::hash<int>()(val.second);
    }
};
class Solution {
    enum DIRECTION { DIRECTION_N, DIRECTION_E, DIRECTION_S, DIRECTION_W };
    vector<pair<int, int>> offset{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

   public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ret = 0;
        int x = 0, y = 0;
        int tox = 0, toy = 0, toxy = 0;
        DIRECTION direction = DIRECTION_N;

        unordered_set<pair<int, int>, hash_pair> dict;
        for (auto& it : obstacles) {
            dict.insert({it[0], it[1]});
        }

        for (int command : commands) {
            if (command == -2) {
                direction = (DIRECTION)((direction + 3) % 4);
            } else if (command == -1) {
                direction = (DIRECTION)((direction + 1) % 4);
            } else {
                for (int i = 0; i < command; ++i) {
                    tox = x + offset[direction].first;
                    toy = y + offset[direction].second;
                    if (dict.count({tox, toy}) > 0) {
                        break;
                    }
                    x = tox;
                    y = toy;
                    ret = max(ret, tox * tox + toy * toy);
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
