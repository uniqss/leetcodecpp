#include "../inc.h"

class Solution {
   public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {}
};

void test(const vector<ComplexVal>& vals, const vector<vector<int>>& expect) {
    auto tree = constructIntTree(vals);
    TreeAutoReleaser _(tree);
    Solution so;
    auto ret = so.listOfDepth(tree);
    vector<vector<int>> retvals;
    for (size_t i = 0; i < ret.size(); ++i) {
        auto retval = list2vals(ret[i]);
        retvals.push_back(retval);
    }
    if (retvals == expect) {
        print("ok");
    } else {
        print("not ok");
        print(vals);
        print(expect);
        print(retvals);
        print();
    }
}

int main() {
    test({1, 2, 3, 4, 5, null, 7, 8}, {{1}, {2, 3}, {4, 5, 7}, {8}});
    return 0;
}
