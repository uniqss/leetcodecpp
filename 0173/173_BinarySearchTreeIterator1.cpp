#include "../inc.h"

class BSTIterator {
    stack<TreeNode*> stk;
    TreeNode* curr;

   public:
    BSTIterator(TreeNode* root) { curr = root; }

    int next() {
        if (curr == nullptr && stk.empty()) return -1;
        while (curr != nullptr) {
            stk.emplace(curr);
            curr = curr->left;
        }
        curr = stk.top();
        stk.pop();
        int ret = curr->val;
        curr = curr->right;
        return ret;
    }

    bool hasNext() { return !stk.empty() || curr != nullptr; }
};

void test(const vector<string>& ops, const vector<vector<ComplexVal>>& params, const vector<ComplexVal>& expect) {
    vector<ComplexVal> ret;
    shared_ptr<BSTIterator> it = nullptr;
    TreeAutoReleaser tree_releaser(nullptr);
    for (int i = 0; i < (int)ops.size(); ++i) {
        const string& op = ops[i];
        const vector<ComplexVal>& param = params[i];
        if (op == "BSTIterator") {
            TreeNode* root = constructIntTree(param);
            tree_releaser.Append(root);
            it = make_shared<BSTIterator>(root);
            ret.emplace_back(null);
        } else if (op == "next") {
            auto curr = it->next();
            ret.emplace_back(curr);
        } else if (op == "hasNext") {
            auto curr = it->hasNext();
            ret.emplace_back(curr);
        }
    }
    assert_eq_ret(expect, ret);
}

int main() {
    test({"BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"},
         {{{7, 3, 15, null, null, 9, 20}}, {}, {}, {}, {}, {}, {}, {}, {}, {}},
         {null, 3, 7, true, 9, true, 15, true, 20, false});
    return 0;
}