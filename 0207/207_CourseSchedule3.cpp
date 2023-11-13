#include "../inc.h"

/*
抄答案第一式：想像成所有节点连成一个连通图，开始都是白色的节点。然后循环从[0-numCourses)如果没访问过，标为黄色中间状态色。再循环它的可达节点，如果可达节点是白色，则dfs。如果可达节点是黄色，失败。
所有可达节点全过，把当前节点涂成绿色，认为它已经通过了考验。再继续
中文官方题解，其实思路很清晰很简洁。
注意，几乎所有这种图状态乱序的问题，都可以考虑这种模式：三个颜色表示三个状态，0未访问状态，1正在遍历中的非稳定中间态、2已访问状态
*/
class Solution {
    vector<vector<int>> nexts;
    vector<int> vis;
    bool valid = true;

   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        nexts.resize(numCourses);
        vis.resize(numCourses);
        for (const auto& it : prerequisites) {
            nexts[it[1]].emplace_back(it[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!vis[i]) dfs(i);
        }
        return valid;
    }
    void dfs(int i) {
        vis[i] = 1;
        for (auto next : nexts[i]) {
            if (vis[next] == 0) {
                dfs(next);
                if (!valid) return;
            } else if (vis[next] == 1) {
                valid = false;
                return;
            }
        }
        vis[i] = 2;
    }
};

void test(int numCourses, vector<vector<int>>&& prerequisites, bool expect) {
    save4print(numCourses, prerequisites);
    assert_eq_ret(expect, Solution().canFinish(numCourses, prerequisites));
}

int main() {
    test(20, {{0, 10}, {3, 18}, {5, 5}, {6, 11}, {11, 14}, {13, 1}, {15, 1}, {17, 4}}, false);
    test(1, {}, true);
    test(2, {{1, 0}}, true);
    test(2, {{1, 0}, {0, 1}}, false);
    return 0;
}
