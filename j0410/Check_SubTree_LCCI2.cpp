#include "../inc.h"

/*
还是用中序硬刚一波，以吃内存为代价看能不能提速。因为并没有交代值范围，所以这里用int64来
刚过了，不过性能有点差
*/
class Solution {
   public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        vector<int64_t> val1, val2;
        auto traverse = [](TreeNode* root, vector<int64_t>& ret) {
            stack<TreeNode*> stk;
            while (root != nullptr || !stk.empty()) {
                while (root != nullptr) {
                    stk.emplace(root);
                    root = root->left;
                }
                root = stk.top();
                stk.pop();
                if (root->left == nullptr) ret.emplace_back((int64_t)INT32_MIN - 1);
                ret.emplace_back(root->val);
                if (root->left != nullptr && root->right == nullptr) ret.emplace_back((int64_t)INT32_MIN - 1);
                root = root->right;
            }
        };
        traverse(t1, val1);
        traverse(t2, val2);
        auto it = std::search(val1.begin(), val1.end(), val2.begin(), val2.end());

        return it != val1.end();
    }
};

void test(const vector<ComplexVal>& v1, const vector<ComplexVal>& v2, bool expect) {
    auto t1 = constructIntTree(v1);
    auto t2 = constructIntTree(v2);
    TreeAutoReleaser _(t1, t2);
    Solution so;
    auto ret = so.checkSubTree(t1, t2);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(v1);
        print(v2);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({1, 2, 3, 4, 5}, {2}, false);
    test({2, 4, null, 3}, {2, 3}, false);
    test({1, 2, null, 4, null, 3}, {2, 3}, false);
    test({1, 2, 3}, {2}, true);
    return 0;
}
