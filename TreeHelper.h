#pragma once

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *constructTree(const vector<int> &vi) {
    if (vi.empty()) {
        return new TreeNode();
    }
    TreeNode *root = new TreeNode(vi[0]);
    list<TreeNode *> parents{root};

    int size = vi.size();
    int count = 0;
    do {
        list<TreeNode *> currLayer;
        for (auto &parent : parents) {
            if (++count < vi.size()) {
                TreeNode *node = new TreeNode(count);
                currLayer.push_back(node);
                parent->left = node;
            } else {
                break;
            }
            if (++count < vi.size()) {
                TreeNode *node = new TreeNode(count);
                currLayer.push_back(node);
                parent->right = node;
            } else {
                break;
            }
        }
        parents = currLayer;

    } while ((size >> 1) > 0);

    return root;
}

void toVector(TreeNode *root, vector<TreeNode *> ret) {
    if (root == nullptr) return;

    queue<TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        TreeNode *curr = nodes.front();
        if (curr == nullptr) continue;
        cout << curr->val << "\t";
        nodes.pop();
        ret.push_back(curr);
        if (curr->left != nullptr) nodes.push(curr->left);
        if (curr->right != nullptr) nodes.push(curr->right);
    }
}

void toVector(const TreeNode *root, vector<const TreeNode *> ret) {
    if (root == nullptr) return;

    queue<const TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        const TreeNode *curr = nodes.front();
        if (curr == nullptr) continue;
        cout << curr->val << "\t";
        nodes.pop();
        ret.push_back(curr);
        if (curr->left != nullptr) nodes.push(curr->left);
        if (curr->right != nullptr) nodes.push(curr->right);
    }
}

void pTree(const TreeNode *root) {
    vector<const TreeNode *> vec;
    toVector(root, vec);

    std::for_each(vec.begin(), vec.end(), [](const TreeNode *node) {
        cout << node->val << "\t";
    });
    cout << endl;
}

void releaseTree(TreeNode *root) {
    vector<TreeNode *> vec;
    toVector(root, vec);

    std::for_each(vec.begin(), vec.end(), [](TreeNode *node) {
        delete node;
    });

    cout << endl;
}
