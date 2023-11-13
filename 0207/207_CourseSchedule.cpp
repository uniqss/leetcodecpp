#include "../inc.h"

class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {}
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
