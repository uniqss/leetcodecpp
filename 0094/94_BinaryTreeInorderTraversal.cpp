#include "../inc.h"

class Solution {
   public:
    vector<int> inorderTraversal(TreeNode* root) {}
};

void test(const vector<ComplexVal>& root, const vector<int>& expect) {
    Solution so;
    TreeNode* tree = constructIntTree(root);
    TreeAutoReleaser _(tree);

    auto ret = so.inorderTraversal(tree);
    if (ret != expect) {
        print("## not ok.");
        print(root);
        print(expect);
        print(ret);
    } else {
        print("ok.");
    }
}

int main() {
    test({4, 2, 6, 1, 3, 5, 7}, {1, 2, 3, 4, 5, 6, 7});
    test({1, null, 2, 3}, {1, 3, 2});
    test({}, {});
    test({1}, {1});
    return 0;
}
