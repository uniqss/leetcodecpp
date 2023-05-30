#include "../inc.h"

class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        auto nullNotEqual = [](TreeNode* l, TreeNode* r) {
            return l == nullptr && r != nullptr || l != nullptr && r == nullptr;
        };
        if (nullNotEqual(p, q)) return false;
        if (p == nullptr) return true;
        queue<TreeNode*> q1, q2;
        q1.emplace(p);
        q2.emplace(q);
        while (!q1.empty() && !q2.empty()) {
            auto size1 = q1.size(), size2 = q2.size();
            if (size1 != size2) return false;
            for (size_t i = 0; i < size1; i++) {
                p = q1.front();
                q = q2.front();
                q1.pop();
                q2.pop();
                if (p->val != q->val) return false;
                if (nullNotEqual(p->left, q->left)) return false;
                if (nullNotEqual(p->right, q->right)) return false;
                if (p->left) {
                    q1.push(p->left);
                    q2.push(q->left);
                }
                if (p->right) {
                    q1.push(p->right);
                    q2.push(q->right);
                }
            }
        }
        return q1.empty() && q2.empty();
    }
};

void test(const vector<ComplexVal>& vp, const vector<ComplexVal>& vq, bool expect) {
    TreeNode* p = constructIntTree(vp);
    TreeAutoReleaser _p(p);
    TreeNode* q = constructIntTree(vq);
    TreeAutoReleaser _q(q);
    Solution so;
    auto ret = so.isSameTree(p, q);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(vp);
        print(vq);
        print(expect);
        print(ret);
    }
}

int main() {
    test({}, {}, true);
    test({1, 2, 3}, {1, 2, 3}, true);
    test({1, 2}, {1, null, 2}, false);
    return 0;
}
