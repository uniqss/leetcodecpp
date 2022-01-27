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
        // 处理一层
        vector<Node *> children;
        for (size_t pidx = 0; pidx < parents.size() && trimed < vi.size(); ++pidx) {
            // 处理一个父节点
            Node *parent = parents[pidx];
            if (children.empty() && vi[trimed].IsNullptr()) {
                ++trimed;
                continue;
            }
            bool parent_has_child = false;
            while (trimed < vi.size() && !vi[trimed].IsNullptr()) {
                parent_has_child = true;
                Node *node = new Node(vi[trimed].vali);
                parent->children.push_back(node);
                children.push_back(node);
                ++trimed;
            }

            if (!parent_has_child) {
                children.push_back(nullptr);
            }
            ++trimed;
        }
        parents = children;
    }

    /*
    处理一层
        处理一个父节点
            定位父节点
            如果是最前端，且子值直接空，无需加入子节点列表
            子值为空
                结束父节点处理并跳出到下一父节点
            子值不为空
                增加一个子值
        已处理完所有父节点
            结束本层处理并跳出到下一层
    层结束
        跳出处理逻辑
    */

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
    if (root == nullptr) return;

    queue<pair<Node *, int>> nodes;
    nodes.push({nullptr, 1});
    nodes.push({root, 100});
    nodes.push({nullptr, 2});
    while (!nodes.empty()) {
        auto curr = nodes.front();
        nodes.pop();
        if (curr.second == 1) {
            cout << "{";
            continue;
        } else if (curr.second == 2) {
            cout << "}";
            continue;
        }

        if (curr.first == nullptr) continue;
        cout << curr.first->val;
        if (curr.second == 0) cout << "\t";

        if (curr.first->children.empty()) continue;
        nodes.push({nullptr, 1});
        for (size_t i = 0; i < curr.first->children.size(); ++i) {
            nodes.push({curr.first->children[i], i == curr.first->children.size() - 1 ? 100 : 0});
        }

        nodes.push({nullptr, 2});
    }

    cout << endl;
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
