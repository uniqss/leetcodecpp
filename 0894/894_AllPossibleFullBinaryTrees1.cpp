#include "../inc.h"

class Solution {
   public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> dp;
        if (n % 2 == 0) return dp;
        if (n == 1) {
            dp.push_back(new TreeNode(0));
            return dp;
        }
        // root 非空，从1开始
        // root 1个，右至少1个，所以左最多n-2
        // 左节点里面的数量，一定是2个2个加
        for (int i = 1; i <= n - 2; i += 2) {
            vector<TreeNode*> l = allPossibleFBT(i);
            vector<TreeNode*> r = allPossibleFBT(n - 1 - i);
            for (auto pleft : l) {
                for (auto pright : r) {
                    TreeNode* curr = new TreeNode(0);
                    curr->left = pleft;
                    curr->right = pright;
                    dp.push_back(curr);
                }
            }
        }

        return dp;
    }
};

void test(int n, vector<vector<ComplexVal>>&& expect) {
    Solution so;
    auto dp = so.allPossibleFBT(n);
    vector<TreeAutoReleaser> tar;
    for_each(dp.begin(), dp.end(), [&tar](TreeNode* root) { tar.push_back(root); });
    vector<vector<ComplexVal>> retvals;
    for_each(dp.begin(), dp.end(), [&retvals](TreeNode* root) {
        retvals.resize(retvals.size() + 1);
        treeToComplexValLevelOrder(root, retvals[retvals.size() - 1]);
    });
    assert_eq_ret(expect, retvals);
    print(n);
}

int main() {
    test(7, {{0, 0, 0, null, null, 0, 0, null, null, 0, 0},
             {0, 0, 0, null, null, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, null, null, null, null, 0, 0},
             {0, 0, 0, 0, 0, null, null, 0, 0}});
    test(3, {{0, 0, 0}});
    return 0;
}
