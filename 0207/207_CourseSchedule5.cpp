#include "../inc.h"

// 太经典了
class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> nexts(numCourses);
        vector<int> incounts(numCourses);
        for (const auto& pre : prerequisites) {
            nexts[pre[1]].emplace_back(pre[0]);
            ++incounts[pre[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (incounts[i] == 0) q.emplace(i);
        }
        int reachable = 0, curr;
        while (!q.empty()) {
            curr = q.front(), q.pop();
            ++reachable;
            for (int next : nexts[curr]) {
                if (--incounts[next] == 0) q.emplace(next);
            }
        }
        return reachable == numCourses;
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
    test(2, {{0, 1}}, true);
    test(2, {{1, 0}, {0, 1}}, false);
    return 0;
}
