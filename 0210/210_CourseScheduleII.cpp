#include "../inc.h"

class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {}
};

void test(int numCourses, vector<vector<int>>&& prerequisites, const vector<int>& expect) {
    save4print(numCourses, prerequisites, expect);
    auto ret = Solution().findOrder(numCourses, prerequisites);
    vector<vector<int>> nexts(numCourses);
    vector<int> incounts(numCourses);
    vector<vector<int>> levelorder;
    for (const auto& pre : prerequisites) {
        nexts[pre[1]].emplace_back(pre[0]);
        ++incounts[pre[0]];
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (incounts[i] == 0) q.emplace(i);
    }
    int reachable = 0;
    while (!q.empty()) {
        int qsize = q.size(), curr, level = 0;
        levelorder.resize(level + 1);
        for (int qi = 0; qi < qsize; ++qi) {
            curr = q.front(), q.pop();
            ++reachable;
            levelorder[level].emplace_back(curr);
            for (int next : nexts[curr]) {
                if (--incounts[next] == 0) q.emplace(next);
            }
        }
        ++level;
    }
    save4print(levelorder);
    do {
        if (expect.empty()) {
            if (!ret.empty()) {
                print("not ok.");
                break;
            } else {
                print("ok.");
                return;
            }
        }
        if (reachable != expect.size()) {
            print("not ok.");
            break;
        }
        bool ok = true;
        for (int i = 0; i < (int)levelorder.size(); ++i) {
            int levelsize = levelorder[i].size();
            sort(levelorder[i].begin(), levelorder[i].end());
            vector<int> expecti(expect.begin(), expect.begin() + levelsize);
            sort(expecti.begin(), expecti.end());
            if (levelorder[i] != expecti) {
                print("not ok");
                ok = false;
                break;
            }
        }
        if (!ok) break;
        print("ok.");
        return;
    } while (false);
    psavedargs();
}

int main() {
    test(3, {{1, 0}, {1, 2}, {0, 1}}, {});
    test(2, {{1, 0}}, {0, 1});
    test(4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}, {0, 2, 1, 3});
    test(1, {}, {0});
    return 0;
}
