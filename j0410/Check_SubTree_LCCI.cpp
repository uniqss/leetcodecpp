#include "../inc.h"

class Solution {
   public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {}
};

void test(const vector<ComplexVal>& v1, const vector<ComplexVal>& v2, bool expect) {
    save4print(v1, v2);
    auto t1 = constructIntTree(v1);
    auto t2 = constructIntTree(v2);
    TreeAutoReleaser _(t1, t2);
    assert_eq_ret(expect, Solution().checkSubTree(t1, t2));
}

int main() {
    test({1, 2, 3, 4, 5}, {2}, false);
    test({2, 4, null, 3}, {2, 3}, false);
    test({1, 2, null, 4, null, 3}, {2, 3}, false);
    test({1, 2, 3}, {2}, true);
    return 0;
}
