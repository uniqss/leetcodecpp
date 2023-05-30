#include "../inc.h"


class Solution {
   public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ret;
        unordered_set<int> deldict;
        deldict.insert(to_delete.begin(), to_delete.end());

        queue<TreeNode*> q;
        q.emplace(root);
        if (deldict.count(root->val) == 0) ret.emplace_back(root);
        while (!q.empty()) {
            auto qsize = q.size();
            for (size_t i = 0; i < qsize; i++) {
                TreeNode* curr = q.front();
                q.pop();
                bool currdel = false;
                if (deldict.count(curr->val) > 0) currdel = true;
                if (curr->left != nullptr) {
                    q.emplace(curr->left);
                    if (deldict.count(curr->left->val) > 0)
                        curr->left = nullptr;
                    else if (currdel)
                        ret.emplace_back(curr->left);
                }
                if (curr->right != nullptr) {
                    q.emplace(curr->right);
                    if (deldict.count(curr->right->val) > 0)
                        curr->right = nullptr;
                    else if (currdel)
                        ret.emplace_back(curr->right);
                }
            }
        }

        return ret;
    }
};

void test(const vector<ComplexVal>& rootvals, const vector<int>& to_delete, vector<vector<ComplexVal>>&& expect) {
    TreeNode* root = constructIntTree(rootvals);
    TreeAutoReleaser _(root);
    Solution so;
    auto to_delete_param = to_delete;
    auto ret = so.delNodes(root, to_delete_param);
    vector<vector<ComplexVal>> retvals;
    retvals.resize(ret.size());
    for (int i = 0; i < ret.size(); i++) {
        TreeNode* node = ret[i];
        treeToComplexValLevelOrder(node, retvals[i], true);
    }

    auto sort = [](vector<vector<ComplexVal>>&& expect) {
        if (expect.size() > 1) {
            for (size_t i = 0; i < expect.size() - 1; i++) {
                for (size_t j = i + 1; j < expect.size(); j++) {
                    if (expect[i][0].vali > expect[j][0].vali) swap(expect[i], expect[j]);
                }
            }
        }
    };
    auto expect_param = expect;
    auto retvals_bk = retvals;
    sort(std::move(expect));
    sort(std::move(retvals));
    if (expect == retvals) {
        print("ok");
    } else {
        print("not ok.");
        print(rootvals);
        print(to_delete);
        print(expect_param);
        print(retvals_bk);
    }
}

int main() {
    test({1, 2, 3, 4, 5, 6, 7}, {3, 5}, {{1, 2, null, 4}, {6}, {7}});
    test({1, 2, 4, null, 3}, {3}, {{1, 2, 4}});
    test({1, 2, null, 4, 3}, {2, 3}, {{1}, {4}});
    return 0;
}
