#include "../inc.h"

// stack
/*
stack的思路:
    找到某节点，若非空，如果left非空，把节点压栈，继续处理left  策略与已同
    找到某节点，若非空，如果left空，结算结点，节点设置为right，继续处理
    栈中元素的处理:如果节点为空，节点取栈顶，并将栈顶出栈，结算栈顶，节点设置为right，继续处理
    这样写比较丑，但比较贴近人的思维
*/
class Solution {
   public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        stack<TreeNode*> stk;
        vector<int> ret;
        while (true) {
            if (curr != nullptr) {
                if (curr->left != nullptr) {
                    stk.push(curr);
                    curr = curr->left;
                    continue;
                } else {
                    ret.push_back(curr->val);
                    curr = curr->right;
                    continue;
                }
            } else {
                if (stk.empty()) break;
                curr = stk.top();
                stk.pop();
                ret.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ret;
    }
};

void test(const vector<ComplexVal>& root, const vector<int>& expect) {
    save4print(root);
    TreeNode* tree = constructIntTree(root);
    TreeAutoReleaser _(tree);
    assert_eq_ret(expect, Solution().inorderTraversal(tree));
}

int main() {
    test({4, 2, 6, 1, 3, 5, 7}, {1, 2, 3, 4, 5, 6, 7});
    test({1, null, 2, 3}, {1, 3, 2});
    test({}, {});
    test({1}, {1});
    test({3, 1, 2}, {1, 3, 2});
    return 0;
}
