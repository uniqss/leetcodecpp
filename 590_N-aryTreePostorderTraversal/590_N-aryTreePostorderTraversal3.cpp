#include "../inc.h"

// 不用reverse，思路和二叉树的postorder类似，先压头节点，再循环栈，【叶节点】或【上次结算节点的父节点】则结算出栈保存上次三步曲，否则逆序压所有子节点
class Solution {
   public:
    vector<int> postorder(Node* root) {
        vector<int> ret;
        if (root == nullptr) return ret;
        stack<Node*> stk;
        stk.emplace(root);
        Node* last = nullptr;
        while (!stk.empty()) {
            root = stk.top();
            if (root->children.empty() || *root->children.rbegin() == last) {
                ret.emplace_back(root->val);
                stk.pop();
                last = root;
            } else {
                std::for_each(root->children.rbegin(), root->children.rend(), [&](Node* n) { stk.emplace(n); });
            }
        }
        return ret;
    }
};

void test(const vector<ComplexVal>& vals, const vector<int>& expect) {
    print(vals);
    Node* root = constructNArrayTree(vals);
    pNArrayTree(root);
    Solution so;
    vector<int> ret = so.postorder(root);
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
    test({1, null, 3, 2, 4, null, 5, 6}, {5, 6, 3, 2, 4, 1});
    test({1, null, 2, 3, 4, 5, null, null, 6, 7, null, 8, null, 9, 10, null, null, 11, null, 12, null, 13, null, null, 14}, {2, 6, 14, 11, 7, 3, 12, 8, 4, 13, 9, 10, 5, 1});
    return 0;
}
