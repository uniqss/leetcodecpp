#include "../inc.h"

class Solution {
   public:
    vector<TreeNode*> allPossibleFBT(int n) {}
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
