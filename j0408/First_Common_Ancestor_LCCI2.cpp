#include "../inc.h"

/*
这个写法太逆天
*/
class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        如果root空，无异议。
        如果root等于其中任意一个，返回root。
        这时候有三种可能：
            另一节点在root左右子树中
            另一节点在root至根路径上
            另一节点在root父的其他兄弟子节点。
        三种情况返回root都是正确的
        这个操作的trick在于，如果另一节点在root的某子孙节点中，不需要访问root的所有子节点。所以有如下结论：
        有一种情况是错的：如果另一节点有可能不在此树中。这样返回的节点是错误的。
        */
        if (root == nullptr || root == p || root == q) return root;
        auto l = lowestCommonAncestor(root->left, p, q);
        auto r = lowestCommonAncestor(root->right, p, q);
        if (l && r) return root;
        return l ? l : r;
    }
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
