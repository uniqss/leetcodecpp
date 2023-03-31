#include "../inc.h"


class Solution {
   public:
    vector<vector<int>> BSTSequences(TreeNode* root) {
        /*
              4
          2      6
        1   3 5    7

        4 2 6 1 3 5 7
        4 6 2 1 3 5 7
        4 2 1 3 6 5 7
        4 2 3 1 6 5 7
        4 2 3 6 1 5 7
        只要父在子前，左右不论的任意组合，包括右在左前、右在左后左左子前、右在左后左左子后左右子前、右在左后在左左子后在左右子后，所有只要父在子前，应该是个backtrack回溯
        
        */
    }
};

void test(const vector<ComplexVal>& vals, vector<vector<int>>&& expect) {
    auto root = constructIntTree(vals);
    TreeAutoReleaser _(root);

    Solution so;
    auto ret = so.BSTSequences(root);
    auto ret_bk = ret;
    std::sort(ret.begin(), ret.end());
    std::sort(expect.begin(), expect.end());
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(vals);
        print(expect);
        print(ret_bk);
        print(ret);
        print();
    }
}

int main() {
    test({2, 1, 3}, {{2, 1, 3}, {2, 3, 1}});
    return 0;
}
