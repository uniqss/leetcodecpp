#pragma once

struct Node {
   public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

Node *constructNArrayTree(const vector<ComplexVal> &vi) {
    if (vi.empty() || vi[0].IsNullptr()) {
        return nullptr;
    }
    Node *root = new Node(vi[0].vali);
    deque<Node *> parents = {root};

    int trimed = 1;
    int layer = 0;
    while (trimed < vi.size()) {
        deque<Node *> currLayer;
        size_t parentNodeCount = parents.size();
        auto it_parent = parents.begin();

        bool is_heading = true;
        while (it_parent != parents.end() && trimed < vi.size()) {
            const ComplexVal &vcurr = vi[trimed];
            if (*it_parent == nullptr) {
                if (vcurr.IsNullptr()) {
                    if (!is_heading) {
                        currLayer.push_back(nullptr);
                    }
                    ++it_parent;
                    ++trimed;
                    continue;
                } else {
                    if (is_heading) {
                        throw std::logic_error("null fater has son");
                    }
                    
                }
            }
        }
        if (trimed >= vi.size()) {
        }

        for (auto &parent : parents) {
            while (trimed < vi.size()) {
            }
        }

        size_t trimedParentCount = 0;
        auto it_parent = parents.begin();
        while (trimed < vi.size() && it_parent != parents.end()) {
            const ComplexVal &vcurr = vi[trimed];
            if (*it_parent == nullptr) {
                if (vcurr.IsNullptr()) {
                    currLayer.push_back(nullptr);
                } else {
                    throw std::logic_error("a null fater have some son, last name is Wang? (姓王?)");
                }
            } else {
                if (vcurr.IsNullptr()) {
                    currLayer.push_back(nullptr);
                } else {
                }
            }
        }

        for (size_t i = 0; i < parentNodeCount; ++i) {
            if (parents[i] == nullptr) {
                currLayer.push_back(nullptr);
                currLayer.push_back(nullptr);
            } else {
                if (vi[trimed].IsNullptr()) {
                    currLayer.push_back(nullptr);
                } else {
                    Node *node = new Node(vi[trimed].vali);
                    parents[i]->left = node;
                    currLayer.push_back(node);
                }
                ++trimed;
                if (trimed >= vi.size()) break;
                if (vi[trimed].IsNullptr()) {
                    currLayer.push_back(nullptr);
                } else {
                    Node *node = new Node(vi[trimed].vali);
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

void NArrayTreeToVector(Node *root, vector<Node *> &ret) {
    if (root == nullptr) return;

    queue<Node *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        auto curr = nodes.front();
        nodes.pop();
        if (curr == nullptr) continue;
        ret.push_back(curr);
        std::for_each(curr->children.begin(), curr->children.end(), [&](Node *&child) { nodes.push(child); });
    }
}

void pNArrayTree(Node *root) {
    vector<Node *> vec;
    NArrayTreeToVector(root, vec);

    std::for_each(vec.begin(), vec.end(), [](const Node *node) {
        cout << node->val << "\t";
    });
    cout << endl;
}

void releaseNArrayTree(Node *root) {
    vector<Node *> vec;
    NArrayTreeToVector(root, vec);

    std::for_each(vec.begin(), vec.end(), [](Node *node) {
        delete node;
    });

    cout << endl;
}

void releaseAllNArrayTreeNodes(vector<Node *> &vec) {
    std::for_each(vec.begin(), vec.end(), [](Node *node) {
        delete node;
    });
    vec.clear();
}
