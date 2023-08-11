#include "../inc.h"

class Solution {
   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        unordered_set<int> keys = {0};
        return dfs(visited, keys, rooms, n, 0);
    }
    bool dfs(vector<bool>& visited, unordered_set<int>& keys, const vector<vector<int>>& rooms, int n,
             int visitedCount) {
        if ((int)keys.size() + visitedCount >= n) return true;
        for (int key : keys) {
            visited[key] = true;
            unordered_set<int> nkeys = keys;
            nkeys.erase(key);
            for (int k : rooms[key]) {
                if (!visited[k]) nkeys.insert(k);
            }
            if (dfs(visited, nkeys, rooms, n, visitedCount + 1)) return true;
        }
        return false;
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
