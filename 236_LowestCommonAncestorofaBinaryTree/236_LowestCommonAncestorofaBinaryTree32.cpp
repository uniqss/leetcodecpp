#include "../stl.h"

// 还是回归1的思路用bfs，但是只用遍历一遍，性能还是会有所提高的，尤其是公共节点比较多的时候
// 这一题用bfs的性能是一定会比dfs高的，在大量测试数据统计均匀分布的情况下。
// 因为【我们一定可以横向剪掉树的某些层以下的叶节点(双节点都遇到了的层以下甚至包括最后一个节点的同层所有右边子节点)】但【我们不能根据一定的条件判定来纵向剪掉某些枝】
class Solution {
    unordered_map<TreeNode*, TreeNode*> fa;
    unordered_map<TreeNode*, bool> visited;

   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root] = nullptr;
        bfs(root, p, q);
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
    void bfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qu;
        qu.emplace(root);
        int count = 0;
        while (!qu.empty()) {
            root = qu.front();
            qu.pop();
            if (root->left != nullptr) {
                qu.emplace(root->left);
                if (root->left == p || root->left == q) ++count;
                fa[root->left] = root;
            }
            if (root->right != nullptr) {
                qu.emplace(root->right);
                if (root->right == p || root->right == q) ++count;
                fa[root->right] = root;
            }
            if (count >= 2) break;
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
        praw("ok.");
    } else {
        praw("not ok.");
        pvcomplex(vals);
        praw(vp);
        praw(vq);
        praw(vexpect);
        praw(retval);
        pnewline();
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
