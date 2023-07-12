#pragma once

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *constructIntBinaryTreeLayerOrder(const vector<int> &vi) {
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

void treeAppendAllNodesToVector(TreeNode *root, vector<TreeNode *> &ret) {
    if (root == nullptr) return;

    queue<TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        TreeNode *curr = nodes.front();
        nodes.pop();
        if (curr == nullptr) continue;
        ret.push_back(curr);
        if (curr->left != nullptr) nodes.push(curr->left);
        if (curr->right != nullptr) nodes.push(curr->right);
    }
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

            for (int i = 0; i < currLayer.size() - nullTail; ++i) {
                ret.emplace_back(currLayer[i]);
            }
        }
    }
}

void treeAppendAllNodesToVector(const TreeNode *root, vector<const TreeNode *> &ret) {
    if (root == nullptr) return;

    queue<const TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        const TreeNode *curr = nodes.front();
        nodes.pop();
        if (curr == nullptr) continue;
        ret.push_back(curr);
        if (curr->left != nullptr) nodes.push(curr->left);
        if (curr->right != nullptr) nodes.push(curr->right);
    }
}

void treeAppendAllNodesToSet(TreeNode *root, unordered_set<TreeNode *> &ret) {
    if (root == nullptr) return;

    queue<TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        auto curr = nodes.front();
        nodes.pop();
        if (curr == nullptr) continue;
        ret.insert(curr);
        if (curr->left != nullptr) nodes.push(curr->left);
        if (curr->right != nullptr) nodes.push(curr->right);
    }
}

ostream &operator<<(ostream &os, const TreeNode *root) {
    vector<const TreeNode *> vec;
    treeAppendAllNodesToVector(root, vec);

    std::for_each(vec.begin(), vec.end(), [&](const TreeNode *node) { os << node->val << "\t"; });
    os << endl;
    return os;
}

void pTreeLevelOrder(const TreeNode *root, bool printNull = true) {
    if (root == nullptr) return;
    cout << "__________ pTreeLevelOrder begin " << endl;

    queue<const TreeNode *> q;
    q.emplace(root);
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
        if (have_valid) cout << line << endl;
    }

    cout << "__________ pTreeLevelOrder end " << endl;
}

void releaseTree(TreeNode *root) {
    vector<TreeNode *> vec;
    treeAppendAllNodesToVector(root, vec);

    std::for_each(vec.begin(), vec.end(), [](TreeNode *node) { delete node; });

    cout << endl;
}

void releaseAllTreeNodes(vector<TreeNode *> &nodes) {
    std::for_each(nodes.begin(), nodes.end(), [](TreeNode *node) { delete node; });
    nodes.clear();
}

void releaseAllTreeNodes(unordered_set<TreeNode *> &nodes) {
    std::for_each(nodes.begin(), nodes.end(), [](TreeNode *node) { delete node; });
    nodes.clear();
}

class TreeAutoReleaser {
    unordered_set<TreeNode *> all_nodes_;

   public:
    TreeAutoReleaser(TreeNode *root) {
        treeAppendAllNodesToSet(root, all_nodes_);
    }
    TreeAutoReleaser(TreeNode *root1, TreeNode *root2) {
        treeAppendAllNodesToSet(root1, all_nodes_);
        treeAppendAllNodesToSet(root2, all_nodes_);
    }
    ~TreeAutoReleaser() { releaseAllTreeNodes(all_nodes_); }
};
