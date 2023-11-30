#pragma once

#include "stl.h"
#include "complexval.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *constructIntTree(const vector<int> &vi) {
    if (vi.empty()) {
        return nullptr;
    }
    vector<TreeNode *> all_nodes(vi.size());

    for (size_t i = 0; i < vi.size(); ++i) {
        all_nodes[i] = new TreeNode(vi[i]);
    }
    for (size_t i = 0; i < all_nodes.size(); ++i) {
        size_t left = i * 2 + 1;
        if (left < all_nodes.size()) all_nodes[i]->left = all_nodes[left];
        size_t right = i * 2 + 2;
        if (right < all_nodes.size()) all_nodes[i]->right = all_nodes[right];
    }
    return all_nodes[0];
}

TreeNode *constructIntTree(const vector<ComplexVal> &vi) {
    if (vi.empty() || vi[0].IsNullptr()) {
        return nullptr;
    }
    TreeNode *root = new TreeNode(vi[0].vali);
    vector<TreeNode *> parents{root};

    size_t trimed = 1;
    int layer = 0;
    while (trimed < vi.size()) {
        vector<TreeNode *> currLayer;
        int parentNodeCount = 1 << layer;
        for (int i = 0; i < parentNodeCount; ++i) {
            if (parents[i] == nullptr) {
                currLayer.push_back(nullptr);
                currLayer.push_back(nullptr);
            } else {
                if (vi[trimed].IsNullptr()) {
                    currLayer.push_back(nullptr);
                } else {
                    TreeNode *node = new TreeNode(vi[trimed].vali);
                    parents[i]->left = node;
                    currLayer.push_back(node);
                }
                ++trimed;
                if (trimed >= vi.size()) break;
                if (vi[trimed].IsNullptr()) {
                    currLayer.push_back(nullptr);
                } else {
                    TreeNode *node = new TreeNode(vi[trimed].vali);
                    parents[i]->right = node;
                    currLayer.push_back(node);
                }
                ++trimed;
                if (trimed >= vi.size()) break;
            }
        }
        parents = currLayer;
        ++layer;
    }

    return root;
}

TreeNode *treeFindUniqueNodeByVal(TreeNode *root, int val) {
    stack<TreeNode *> stk;
    while (root != nullptr || !stk.empty()) {
        while (root != nullptr) {
            stk.emplace(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        if (root->val == val) return root;
        root = root->right;
    }
    return nullptr;
}

bool __treeIsBST(TreeNode *root, int64_t vmin, int64_t vmax) {
    if (root == nullptr) return true;
    if (root->val <= vmin || root->val >= vmax) return false;
    return __treeIsBST(root->left, vmin, root->val) && __treeIsBST(root->right, root->val, vmax);
}
bool treeIsBST(TreeNode *root) {
    return __treeIsBST(root, (int64_t)INT_MIN - 1, (int64_t)INT_MAX + 1);
}

void treeToIntVecLevelOrder(const TreeNode *root, vector<int> &ret) {
    if (root == nullptr) return;
    queue<const TreeNode *> q;
    q.emplace(root);
    while (!q.empty()) {
        auto qsize = q.size();
        for (size_t i = 0; i < qsize; ++i) {
            const TreeNode *curr = q.front();
            q.pop();
            ret.emplace_back(curr->val);
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
    }
}

void treeToComplexValLevelOrder(const TreeNode *root, vector<ComplexVal> &ret, bool append_null_middle = true) {
    if (root == nullptr) return;
    queue<const TreeNode *> q;
    q.emplace(root);
    while (!q.empty()) {
        auto qsize = q.size();
        vector<ComplexVal> currLayer;
        bool haveValid = false;
        bool haveChildren = false;
        for (size_t i = 0; i < qsize; ++i) {
            const TreeNode *curr = q.front();
            q.pop();
            if (curr != nullptr) {
                haveValid = true;
                currLayer.emplace_back(curr->val);
                if (curr->left != nullptr) {
                    q.push(curr->left);
                    haveChildren = true;
                } else {
                    q.push(nullptr);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                    haveChildren = true;
                } else {
                    q.push(nullptr);
                }
            } else {
                currLayer.emplace_back(nullptr);
            }
        }
        if (haveValid) {
            int nullTail = 0;
            for (int i = currLayer.size() - 1; i >= 0; --i) {
                if (currLayer[i] == nullptr) {
                    ++nullTail;
                } else
                    break;
            }

            if (nullTail > 0 && append_null_middle && haveChildren) {
                --nullTail;
            }

            for (int i = 0; i < (int)currLayer.size() - nullTail; ++i) {
                ret.emplace_back(currLayer[i]);
            }
        }
    }
}

void treeBFS(const TreeNode *root, std::function<void(const TreeNode *)> fn) {
    if (root == nullptr) return;
    queue<const TreeNode *> nodes;
    nodes.emplace(root);
    while (!nodes.empty()) {
        root = nodes.front(), nodes.pop();
        fn(root);
        if (root->left != nullptr) nodes.emplace(root->left);
        if (root->right != nullptr) nodes.emplace(root->right);
    }
}
void treeBFS(TreeNode *root, std::function<void(TreeNode *)> fn) {
    if (root == nullptr) return;
    queue<TreeNode *> nodes;
    nodes.emplace(root);
    while (!nodes.empty()) {
        root = nodes.front(), nodes.pop();
        if (root->left != nullptr) nodes.emplace(root->left);
        if (root->right != nullptr) nodes.emplace(root->right);
        fn(root);
    }
}

void treeDFSPreOrder(const TreeNode *root, std::function<void(const TreeNode *)> fn) {
    if (root == nullptr) return;
    stack<const TreeNode *> stk;
    stk.emplace(root);
    while (!stk.empty()) {
        root = stk.top(), stk.pop();
        if (root->right != nullptr) stk.emplace(root->right);
        if (root->left != nullptr) stk.emplace(root->left);
        fn(root);
    }
}

void treeToIntVecPreOrder(const TreeNode *root, vector<int> &ret) {
    treeDFSPreOrder(root, [&ret](const TreeNode *curr) { ret.emplace_back(curr->val); });
}

ostream &operator<<(ostream &os, const TreeNode *root) {
    bool printNull = true;
    os << " (tree level order):[ " << endl;
    queue<const TreeNode *> q;
    if (root != nullptr) q.emplace(root);
    while (!q.empty()) {
        auto qsize = q.size();
        bool have_valid = false;
        std::string line = "";
        for (size_t i = 0; i < qsize; ++i) {
            root = q.front();
            q.pop();
            if (root == nullptr) {
                line += " null";
                continue;
            }
            line += " " + std::to_string(root->val);
            have_valid = true;

            if (root->left != nullptr) q.emplace(root->left);
            if (printNull && root->left == nullptr) q.emplace(nullptr);
            if (root->right != nullptr) q.emplace(root->right);
            if (printNull && root->right == nullptr) q.emplace(nullptr);
        }
        if (have_valid) os << line << endl;
    }

    os << "]\t";
    return os;
}

struct TreeNodesMemHolder {
    unordered_set<TreeNode *> all_nodes_;
    ~TreeNodesMemHolder() { deleteAndClearPtrContainer(all_nodes_); }
};

inline static TreeNodesMemHolder gs_tree_nodes_mem_holder;

class TreeAutoReleaser {
   public:
    TreeAutoReleaser(TreeNode *root) { Append(root); }
    TreeAutoReleaser(TreeNode *root1, TreeNode *root2) { Append(root1), Append(root2); }
    void Append(TreeNode *root) {
        treeBFS(root, [](TreeNode *curr) { gs_tree_nodes_mem_holder.all_nodes_.emplace(curr); });
    }
};
