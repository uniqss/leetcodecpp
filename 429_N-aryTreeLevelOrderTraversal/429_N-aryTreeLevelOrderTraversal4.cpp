#include "../inc.h"

// recursive
class Solution {
   public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};

        vector<vector<int>> ret;
        helper(ret, root, 0);

        return ret;
    }
    void helper(vector<vector<int>>& ret, Node* root, size_t level) {
        if (ret.size() <= level) {
            ret.resize(ret.size() + 1);
        }
        ret[level].push_back(root->val);
        for (Node* child : root->children) {
            helper(ret, child, level + 1);
        }
    }
};

void test(const vector<ComplexVal>& vals, const vector<vector<int>>& expect) {
    print(vals);
    Node* root = constructNArrayTree(vals);
    pNArrayTree(root);
    Solution so;
    auto ret = so.levelOrder(root);
    if (ret != expect) {
        print("not ok");
        print(vals);
        print(expect);
        print(ret);
    } else {
        print("ok.");
    }
}

int main() {
    test({1, null, 3, 2, 4, null, 5, 6}, {{1}, {3, 2, 4}, {5, 6}});
    test({1, null, 2, 3, 4, 5, null, null, 6, 7, null, 8, null, 9, 10, null, null, 11, null, 12, null, 13, null, null, 14}, {{1}, {2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13}, {14}});
    return 0;
}
