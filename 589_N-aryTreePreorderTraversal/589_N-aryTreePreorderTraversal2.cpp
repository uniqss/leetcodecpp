#include "../inc.h"

// stack
class Solution {
   public:
    vector<int> preorder(Node* root) {
        if (root == nullptr) return {};
        vector<int> ret;
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            ret.push_back(root->val);
            std::for_each(root->children.rbegin(), root->children.rend(), [&](Node* node) { stk.push(node); });
        }
        return ret;
    }
};

void test(const vector<ComplexVal>& vals, const vector<int>& expect) {
    Node* root = constructNArrayTree(vals);
    Solution so;
    vector<int> ret = so.preorder(root);
    if (ret != expect) {
        print("not ok");
        print(vals);
        print(root);
        print(expect);
        print(ret);
    } else {
        print("ok.");
    }
}

int main() {
    test({1, null, 3, 2, 4, null, 5, 6}, {1, 3, 5, 6, 2, 4});
    test({1, null, 2,    3,    4,  5,    null, null, 6,  7,    null, 8, null,
          9, 10,   null, null, 11, null, 12,   null, 13, null, null, 14},
         {1, 2, 3, 6, 7, 11, 14, 4, 8, 12, 5, 9, 13, 10});
    return 0;
}
