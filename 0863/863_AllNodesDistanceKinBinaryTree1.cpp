#include "../inc.h"

class Solution {
   public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k == 0) return {target->val};
        vector<int> ret;
        unordered_map<TreeNode*, TreeNode*> parents;
        unordered_set<TreeNode*> omit;
        parents[root] = nullptr;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            auto qsize = q.size();
            for (size_t i = 0; i < qsize; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left != nullptr) {
                    q.emplace(curr->left);
                    parents[curr->left] = curr;
                }
                if (curr->right != nullptr) {
                    q.emplace(curr->right);
                    parents[curr->right] = curr;
                }
            }
        }

        helper(target, k, omit, ret);

        while (!q.empty()) q.pop();
        TreeNode* uproot = target;
        int upcount = 0;
        while (uproot != root && ++upcount <= k) {
            omit.insert(uproot);
            uproot = parents[uproot];
        }

        upcount = 0;
        TreeNode* currroot = parents[target];
        while (currroot != parents[uproot]) {
            ++upcount;
            helper(currroot, k - upcount, omit, ret);
            currroot = parents[currroot];
        }

        return ret;
    }
    void helper(TreeNode* root, int depth, unordered_set<TreeNode*>& omit, vector<int>& ret) {
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty() && --depth >= 0) {
            auto qsize = q.size();
            for (size_t i = 0; i < qsize; ++i) {
                root = q.front();
                q.pop();
                if (root->left && omit.count(root->left) == 0) q.emplace(root->left);
                if (root->right && omit.count(root->right) == 0) q.emplace(root->right);
            }
        }

        while (!q.empty()) {
            ret.emplace_back(q.front()->val);
            q.pop();
        }
    }
};

void test(const vector<ComplexVal>& vals, int target, int k, vector<int>&& expect) {
    Solution so;
    TreeNode* root = constructIntTree(vals);
    TreeAutoReleaser _(root);
    TreeNode* tnode = treeFindUniqueNodeByVal(root, target);
    auto ret = so.distanceK(root, tnode, k);
    sort(expect.begin(), expect.end());
    sort(ret.begin(), ret.end());
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(vals);
        print(target);
        print(k);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({0, 1, null, null, 2, null, 3, null, 4}, 3, 0, {3});
    test({0, 1, null, 3, 2}, 2, 1, {1});
    test({3, 5, 1, 6, 2, 0, 8, null, null, 7, 4}, 5, 2, {7, 4, 1});
    test({1}, 1, 3, {});
    return 0;
}
