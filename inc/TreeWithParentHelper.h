#pragma once

class Node {
   public:
    int val;
    Node *left;
    Node *right;
    Node *parent;
};

void clearNode(Node *n) {
    n->val = 0;
    n->left = nullptr;
    n->right = nullptr;
    n->parent = nullptr;
}

void setNodeVal(Node *n, int val) {
    n->val = val;
    n->left = nullptr;
    n->right = nullptr;
    n->parent = nullptr;
}

Node *constructIntTree(const std::vector<ComplexVal> &vi) {
    if (vi.empty() || vi[0].IsNullptr()) {
        return nullptr;
    }
    auto *root = new Node();
    setNodeVal(root, vi[0].vali);

    vector<Node *> parents{root};

    size_t trimed = 1;
    int layer = 0;
    while (trimed < vi.size()) {
        vector<Node *> currLayer;
        int parentNodeCount = 1 << layer;
        for (int i = 0; i < parentNodeCount; ++i) {
            if (parents[i] == nullptr) {
                currLayer.push_back(nullptr);
                currLayer.push_back(nullptr);
            } else {
                if (vi[trimed].IsNullptr()) {
                    currLayer.push_back(nullptr);
                } else {
                    Node *node = new Node();
                    setNodeVal(node, vi[trimed].vali);
                    parents[i]->left = node;
                    node->parent = parents[i];
                    currLayer.push_back(node);
                }
                ++trimed;
                if (trimed >= vi.size()) break;
                if (vi[trimed].IsNullptr()) {
                    currLayer.push_back(nullptr);
                } else {
                    Node *node = new Node();
                    setNodeVal(node, vi[trimed].vali);
                    parents[i]->right = node;
                    node->parent = parents[i];
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

Node *treeWithParentFindUniqueNodeByVal(Node *root, int val) {
    stack<Node *> stk;
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

void treeToIntVecLevelOrder(const Node *root, vector<int> &ret) {
    if (root == nullptr) return;
    queue<const Node *> q;
    q.emplace(root);
    while (!q.empty()) {
        auto qsize = q.size();
        for (size_t i = 0; i < qsize; ++i) {
            const Node *curr = q.front();
            q.pop();
            ret.emplace_back(curr->val);
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
    }
}

void treeToVector(Node *root, vector<Node *> &ret) {
    if (root == nullptr) return;

    queue<Node *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        Node *curr = nodes.front();
        nodes.pop();
        if (curr == nullptr) continue;
        ret.push_back(curr);
        if (curr->left != nullptr) nodes.push(curr->left);
        if (curr->right != nullptr) nodes.push(curr->right);
    }
}

void releaseAllTreeNodes(vector<Node *> &vec) {
    std::for_each(vec.begin(), vec.end(), [](Node *node) { delete node; });
    vec.clear();
}

class TreeWithParentAutoReleaser {
    Node *root_;
    vector<Node *> all_nodes_;

   public:
    TreeWithParentAutoReleaser(Node *root) : root_(root) { treeToVector(root, all_nodes_); }
    ~TreeWithParentAutoReleaser() { releaseAllTreeNodes(all_nodes_); }
};
