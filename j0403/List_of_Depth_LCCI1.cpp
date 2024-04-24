#include "../inc.h"

class Solution {
   public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        if (tree == nullptr) return {};
        queue<TreeNode*> q;
        vector<ListNode*> ret;
        q.push(tree);
        while (!q.empty()) {
            auto qsize = q.size();
            ListNode fake(0, nullptr);
            ListNode* tail = &fake;
            for (size_t i = 0; i < qsize; ++i) {
                auto curr = q.front();
                q.pop();
                ListNode* node = new ListNode(curr->val, nullptr);
                tail->next = node;
                tail = node;
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }
            if (fake.next != nullptr) {
                ret.push_back(fake.next);
            }
        }
        return ret;
    }
};

void test(const vector<ComplexVal>& vals, const vector<vector<int>>& expect) {
    save4print(vals);
    auto tree = constructIntTree(vals);
    TreeAutoReleaser _(tree);
    auto ret = Solution().listOfDepth(tree);
    vector<vector<int>> retvals;
    for (size_t i = 0; i < ret.size(); ++i) {
        auto retval = list2vals(ret[i]);
        retvals.push_back(retval);
    }
    assert_eq_ret(expect, retvals);
}

int main() {
    test({1, 2, 3, 4, 5, null, 7, 8}, {{1}, {2, 3}, {4, 5, 7}, {8}});
    return 0;
}
