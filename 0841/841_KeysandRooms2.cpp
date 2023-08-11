#include "../inc.h"

class Solution {
    vector<bool> vis;
    int num;

   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vis.resize(rooms.size());
        num = 0;
        dfs(rooms, 0);
        return num == rooms.size();
    }
    void dfs(vector<vector<int>>& rooms, int x) {
        vis[x] = true;
        ++num;
        for (int k : rooms[x]) {
            if (!vis[k]) {
                dfs(rooms, k);
            }
        }
    }
};

void test(vector<vector<int>>&& rooms, bool expect) {
    Solution so;
    auto ret = so.canVisitAllRooms(rooms);
    assert_eq_ret(expect, ret);
    print(rooms);
}

int main() {
    test({{1}, {2}, {3}, {}}, true);
    test({{1, 3}, {3, 0, 1}, {2}, {0}}, false);
    return 0;
}
