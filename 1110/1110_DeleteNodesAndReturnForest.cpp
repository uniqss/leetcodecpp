#include "../inc.h"


class Solution {
   public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {}
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
        treeToComplexValLevelOrder(node, retvals[i]);
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
