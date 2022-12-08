#include "../inc.h"

// dfs的优化
class Solution {
    unordered_map<TreeNode*, TreeNode*> fa;
    unordered_map<TreeNode*, bool> visited;

   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root] = nullptr;
        dfs(root);
        while (p != nullptr) {
            visited[p] = true;
            p = fa[p];
        }
        while (q != nullptr) {
            if (visited[q]) return q;
            q = fa[q];
        }
        return nullptr;
    }
    void dfs(TreeNode* root) {
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->left != nullptr) fa[root->left] = root;
            if (root->right != nullptr) fa[root->right] = root;
            root = root->right;
        }
    }
};

void test(vector<ComplexVal>&& vals, int vp, int vq, int vexpect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    TreeNode* p = treeFindUniqueNodeByVal(root, vp);
    TreeNode* q = treeFindUniqueNodeByVal(root, vq);
    Solution so;
    TreeNode* ret = so.lowestCommonAncestor(root, p, q);
    int retval = ret->val;
    if (retval == vexpect) {
        print("ok.");
    } else {
        print("not ok.");
        print(vals);
        print(vp);
        print(vq);
        print(vexpect);
        print(retval);
        print();
    }
}

int main() {
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 0, 8, 1);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 1, 3);
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 4, 5);
    test({1, 2}, 1, 2, 1);
    return 0;
}

/*
[3,5,1,6,2,0,8,null,null,7,4]
5
1
[3,5,1,6,2,0,8,null,null,7,4]
5
4
[1,2]
1
2
[3,5,1,6,2,0,8,null,null,7,4]
0
8

*/
