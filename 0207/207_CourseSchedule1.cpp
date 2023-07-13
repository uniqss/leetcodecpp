#include "../inc.h"

class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) return true;
        unordered_map<int, unordered_set<int>> dict;
        unordered_set<int> taken;
        for (int i = 0; i < numCourses; ++i) {
            taken.insert(i);
        }

        for (auto pre : prerequisites) {
            dict[pre[0]].insert(pre[1]);
            taken.erase(pre[0]);
        }
        if (taken.empty()) return false;
        while (true) {
            vector<int> currtaken;
            for (auto it = dict.begin(); it != dict.end();) {
                if (taken.count(it->first) > 0) {
                    it = dict.erase(it);
                    continue;
                }
                bool prefinished = true;
                for (auto pre : it->second) {
                    if (taken.count(pre) > 0) continue;
                    prefinished = false;
                    break;
                }
                if (prefinished) {
                    currtaken.emplace_back(it->first);
                    it = dict.erase(it);
                    continue;
                }
                ++it;
            }
            if (currtaken.empty()) return false;
            taken.insert(currtaken.begin(), currtaken.end());
            if (taken.size() == numCourses) return true;
        }
    }
};

void test(int numCourses, vector<vector<int>>&& prerequisites, bool expect) {
    auto prerequisites_param = prerequisites;
    Solution so;
    auto ret = so.canFinish(numCourses, prerequisites);
    assert_eq_ret(expect, ret);
    print(numCourses);
    print(prerequisites_param);
}

int main() {
    test(1, {}, true);
    test(2, {{1, 0}}, true);
    test(2, {{1, 0}, {0, 1}}, false);
    return 0;
}
