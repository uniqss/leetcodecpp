#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;
        queue<tuple<TreeNode*, int, vector<int>>> q;
        q.push({root, 0, {}});
        int sum = 0;
        while (!q.empty()) {
            auto qsize = q.size();
            for (size_t i = 0; i < qsize; ++i) {
                root = get<0>(q.front());
                sum = get<1>(q.front());
                vector<int> path = get<2>(q.front());
                q.pop();
                if (root->left == nullptr && root->right == nullptr) {
                    if (sum + root->val == targetSum) {
                        path.push_back(root->val);
                        ret.emplace_back(path);
                    }
                    continue;
                }
                sum += root->val;
                if (root->left) {
                    path.push_back(root->val);
                    q.push({root->left, sum, path});
                    path.pop_back();
                }
                if (root->right) {
                    path.push_back(root->val);
                    q.push({root->right, sum, path});
                    path.pop_back();
                }
            }
        }
        return ret;
    }
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
