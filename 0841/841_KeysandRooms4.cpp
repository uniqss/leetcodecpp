#include "../inc.h"

class Solution {
   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.emplace(0);
        int rsize = rooms.size(), entered = 0;
        vector<bool> vis(rsize);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (vis[curr]) continue;
            vis[curr] = true;
            ++entered;
            for (int k : rooms[curr]) {
                if (!vis[k]) q.emplace(k);
            }
        }
        return entered == rsize;
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
