#include "../stl.h"

// stack 经典写法
/*
只要当前节点非空，一直压栈并左移当前节点
出栈到当前节点
当前节点右空或右为上一次结算节点，结算当前节点
否则将当前节点压栈，并右移当前节点

节点的几种情况：
左右皆空    出栈则结算
左空右不空  首次出栈需再度压栈并右移当前节点，二次出栈结算。规律：结算时右节点一定是上一次结算的节点
左不空右空  出栈则结算
左右皆不空  首次出栈需再度压栈并右移当前节点，二次出栈结算。规律：结算时右节点一定是上一次结算的节点
规律：右空结算，右为上一次结算节点结算。否则继续压栈并右移
不断压栈当前节点并左移直到空，然后出栈
*/
class Solution {
   public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        TreeNode* last = nullptr;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->right == nullptr || root->right == last) {
                ret.emplace_back(root->val);
                last = root;
                root = nullptr;
            } else {
                stk.push(root);
                root = root->right;
            }
        }
        return ret;
    }
};

void test(const vector<ComplexVal>& root, const vector<int>& expect) {
    Solution so;
    TreeNode* tree = constructIntTree(root);
    vector<TreeNode*> allNodes;
    treeToVector(tree, allNodes);

    auto ret = so.postorderTraversal(tree);
    if (ret != expect) {
        praw("## not ok.");
        pvcomplex(root);
        pvraw(expect);
        pvraw(ret);
    } else {
        praw("ok.");
    }

    releaseAllTreeNodes(allNodes);
}

int main() {
    test({1, null, 2, 3}, {3, 2, 1});
    test({}, {});
    test({1}, {1});

    test({4, 2, 6, 1, 3, 5, 7}, {1, 3, 2, 5, 7, 6, 4});
    return 0;
}
