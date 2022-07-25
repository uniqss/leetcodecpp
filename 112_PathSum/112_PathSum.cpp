#include "../inc.h"

class Solution {
   public:
    bool hasPathSum(TreeNode* root, int targetSum) {}
};

void test(const vector<ComplexVal>& vals, int targetsum, bool expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.hasPathSum(root, targetsum);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(vals);
        print(targetsum);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({1, 2}, 1, false);
    test({}, 0, false);
    test({5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1}, 22, true);
    test({1, 2, 3}, 5, false);

    return 0;
}
