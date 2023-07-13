#include "../inc.h"

class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {}
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
