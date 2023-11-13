#include "../inc.h"

/*
硬刚第二式
*/
class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> deps;
        vector<bool> taken(numCourses, false);
        int count = 0;
        for (auto p : prerequisites) {
            deps[p[0]].insert(p[1]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (deps.count(i) == 0) {
                taken[i] = true;
                ++count;
            }
        }
        while (true) {
            queue<int> q;
            for (const auto& [course, dep] : deps) {
                if (taken[course]) continue;
                bool cantake = true;
                for (auto it : dep) {
                    if (!taken[it]) {
                        cantake = false;
                        break;
                    }
                }
                if (cantake) {
                    q.emplace(course);
                }
            }
            if (q.empty()) break;
            while (!q.empty()) {
                auto curr = q.front();
                q.pop();
                if (!taken[curr]) {
                    taken[curr] = true;
                    ++count;
                }
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
    test(2, {{1, 0}, {0, 1}}, false);
    return 0;
}
