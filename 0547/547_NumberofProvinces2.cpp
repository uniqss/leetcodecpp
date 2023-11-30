#include "../inc.h"

class Solution {
   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        int provinces = 0;
        vector<bool> vis(cities);
        for (int i = 0; i < cities; ++i) {
            if (!vis[i]) {
                queue<int> q;
                q.emplace(i);
                while (!q.empty()) {
                    int j = q.front();
                    q.pop();
                    vis[j] = true;
                    for (int k = 0; k < cities; ++k) {
                        if (isConnected[j][k] == 1 && !vis[k]) {
                            q.push(k);
                        }
                    }
                }
                ++provinces;
            }
        }
        return provinces;
    }
};

void test(vector<vector<int>>&& isConnected, int expect) {
    save4print(isConnected);
    assert_eq_ret(expect, Solution().findCircleNum(isConnected));
}

int main() {
    test({{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}}, 1);
    test({{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}, 2);
    test({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, 3);
    return 0;
}
