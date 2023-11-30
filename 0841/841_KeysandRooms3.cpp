#include "../inc.h"

class Solution {
   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int rsize = rooms.size(), entered = 0;
        vector<bool> vis(rsize);
        dfs(rooms, vis, 0, rsize, entered);
        return entered == rsize;
    }
    void dfs(vector<vector<int>>& rooms, vector<bool>& vis, int curr, int rsize, int& entered) {
        vis[curr] = true;
        ++entered;
        for (int k : rooms[curr]) {
            if (!vis[k]) dfs(rooms, vis, k, rsize, entered);
        }
    }
};

void test(vector<vector<int>>&& rooms, bool expect) {
    save4print(rooms);
    assert_eq_ret(expect, Solution().canVisitAllRooms(rooms));
}

int main() {
    test({{1}, {2}, {3}, {}}, true);
    test({{1, 3}, {3, 0, 1}, {2}, {0}}, false);
    return 0;
}
