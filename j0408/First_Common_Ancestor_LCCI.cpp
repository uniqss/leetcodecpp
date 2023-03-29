#include "../inc.h"

class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {}
};

void test(const vector<ComplexVal>& vals, int pv, int qv, int expect) {
    auto root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    auto p = treeFindUniqueNodeByVal(root, pv);
    auto q = treeFindUniqueNodeByVal(root, qv);
    Solution so;
    auto ret = so.lowestCommonAncestor(root, p, q);
    if (ret == nullptr || ret->val != expect) {
        print("not ok");
        print(vals);
        print(pv);
        print(qv);
        print(expect);
        print(ret);
        print();
    } else {
        print("ok");
    }
}

int main() {
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 4, 5);
    test({3, 5, 1}, 5, 1, 3);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 1, 3);
    return 0;
}
