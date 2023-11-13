#include "../inc.h"

/*
抄答案第二式：bfs的精简写法，比我写的精炼多了。思路是一样的。
这里非常取巧，用了个计数表达以这个点为终点的所有点的集合。
*/
class Solution {
    vector<vector<int>> nexts;
    vector<int> incount;

   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        nexts.resize(numCourses);
        incount.resize(numCourses);
        for (auto it : prerequisites) {
            nexts[it[1]].emplace_back(it[0]);
            ++incount[it[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (incount[i] == 0) q.emplace(i);
        }
        int count = 0;
        while (!q.empty()) {
            ++count;
            auto curr = q.front();
            q.pop();
            for (auto next : nexts[curr]) {
                if (--incount[next] == 0) q.emplace(next);
            }
        }
        return count == numCourses;
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
