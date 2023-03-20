#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {}
};

void test(const vector<ComplexVal>& vals, int targetsum, vector<vector<int>>&& expect) {
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    Solution so;
    auto ret = so.pathSum(root, targetsum);
    for_each(expect.begin(), expect.end(), [](vector<int>& vi) { sort(vi.begin(), vi.end()); });
    sort(expect.begin(), expect.end());
    for_each(ret.begin(), ret.end(), [](vector<int>& vi) { sort(vi.begin(), vi.end()); });
    sort(ret.begin(), ret.end());
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(vals);
        print(targetsum);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({}, 0, {});
    test({5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1}, 22, {{5, 4, 11, 2}, {5, 8, 4, 5}});
    test({1, 2, 3}, 5, {});

    return 0;
}
