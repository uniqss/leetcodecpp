#include "../inc.h"

// 中文站官方解法 这个做法思路也很清晰，但不推荐。因为要遍历整棵树，随便dfs 还是bfs在树非常巨大的情况下，数学平均都是50%，而这里是100%，CPU内存都很差
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
        if (root->left != nullptr) {
            fa[root->left] = root;
            dfs(root->left);
        }
        if (root->right != nullptr) {
            fa[root->right] = root;
            dfs(root->right);
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
