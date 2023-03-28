#include "../inc.h"

class Solution {
   public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {}
};

void test(const vector<ComplexVal>& vals, int pv, ComplexVal expect) {
    auto root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto p = treeFindUniqueNodeByVal(root, pv);
    auto ret = so.inorderSuccessor(root, p);
    ComplexVal retval = null;
    if (ret != nullptr) retval = ret->val;
    if (retval == expect) {
        print("ok");
    } else {
        print("not ok");
        print(vals);
        print(pv);
        print(expect);
        print(retval);
        print();
    }
}

int main() {
    test({2, 1, 3}, 1, 2);
    test({5, 3, 6, 2, 4, null, null, 1}, 6, null);
    return 0;
}
