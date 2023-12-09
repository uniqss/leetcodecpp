#pragma once

struct Node {
   public:
    int val;
    vector<Node *> children;

    Node() {}
    Node(int _val) { val = _val; }
    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

Node *constructNArrayTree(const vector<ComplexVal> &vi) {
    if (vi.empty() || vi[0].IsNullptr()) {
        return nullptr;
    }
    size_t trimed = 0;
    Node *root = new Node(vi[trimed].vali);
    ++trimed;
    if (!vi[trimed].IsNullptr()) throw std::logic_error("val second must be null");
    ++trimed;
    vector<Node *> parents = {root};
    while (trimed < vi.size()) {
        vector<Node *> children;
        for (size_t pidx = 0; pidx < parents.size() && trimed < vi.size(); ++pidx) {
            Node *parent = parents[pidx];
            if (children.empty() && vi[trimed].IsNullptr()) {
                ++trimed;
                continue;
            }
            bool parent_has_child = false;
            while (trimed < vi.size() && !vi[trimed].IsNullptr()) {
                parent_has_child = true;
                Node *node = new Node(vi[trimed].vali);
                parent->children.emplace_back(node);
                children.emplace_back(node);
                ++trimed;
            }

            if (!parent_has_child) {
                children.emplace_back(nullptr);
            }
            ++trimed;
        }
        parents = children;
    }

    return root;
}

void NArrayTreeToVector(Node *root, vector<Node *> &ret) {
    if (root == nullptr) return;

    queue<Node *> nodes;
    nodes.emplace(root);
    while (!nodes.empty()) {
        auto curr = nodes.front();
        nodes.pop();
        if (curr == nullptr) continue;
        ret.emplace_back(curr);
        std::for_each(curr->children.begin(), curr->children.end(), [&](Node *&child) { nodes.emplace(child); });
    }
}

ostream &operator<<(ostream &os, const Node *root) {
    if (root == nullptr) return os;

    queue<pair<const Node *, int>> nodes;
    nodes.push({nullptr, 1});
    nodes.push({root, 100});
    nodes.push({nullptr, 2});
    while (!nodes.empty()) {
        auto curr = nodes.front();
        nodes.pop();
        if (curr.second == 1) {
            os << "{";
            continue;
        } else if (curr.second == 2) {
            os << "}";
            continue;
        }

        if (curr.first == nullptr) continue;
        os << curr.first->val;
        if (curr.second == 0) os << "\t";

        if (curr.first->children.empty()) continue;
        nodes.push({nullptr, 1});
        for (size_t i = 0; i < curr.first->children.size(); ++i) {
            nodes.push({curr.first->children[i], i == curr.first->children.size() - 1 ? 100 : 0});
        }

        nodes.push({nullptr, 2});
    }

    os << endl;
    return os;
}

void releaseNArrayTree(Node *root) {
    vector<Node *> vec;
    NArrayTreeToVector(root, vec);

    std::for_each(vec.begin(), vec.end(), [](Node *node) { delete node; });

    cout << endl;
}

void releaseAllNArrayTreeNodes(vector<Node *> &vec) {
    std::for_each(vec.begin(), vec.end(), [](Node *node) { delete node; });
    vec.clear();
}
