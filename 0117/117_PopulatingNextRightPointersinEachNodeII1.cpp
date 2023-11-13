#include "../helpers/stl.h"
#include "../helpers/complexval.h"
#include "../helpers/uassert.h"

#define null nullptr
#define LTEND null

class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
   public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        vector<Node*> lastlayer;
        lastlayer.emplace_back(root);
        while (!lastlayer.empty()) {
            vector<Node*> currlayer;
            for (auto node : lastlayer) {
                if (node->left) currlayer.emplace_back(node->left);
                if (node->right) currlayer.emplace_back(node->right);
            }
            for (int i = 0; i < (int)currlayer.size() - 1; ++i) {
                currlayer[i]->next = currlayer[i + 1];
            }
            lastlayer = currlayer;
        }
        return root;
    }
};

Node* ConstructLinerTree(const vector<ComplexVal>& vals) {
    if (vals.empty() || vals[0] == nullptr) return nullptr;
    vector<Node*> lastlayer;
    int idx = 0, vsize = vals.size();
    Node* root = new Node(vals[0].vali);
    lastlayer.emplace_back(root);
    ++idx;
    while (idx < vsize) {
        vector<Node*> currlayer;
        for (int i = 0; i < lastlayer.size() && idx < vsize; ++i) {
            Node* parent = lastlayer[i];
            if (parent == nullptr) continue;
            if (idx < vsize) {
                if (vals[idx].IsNullptr()) {
                    currlayer.emplace_back(nullptr);
                } else {
                    Node* l = new Node(vals[idx].vali);
                    parent->left = l;
                    currlayer.emplace_back(l);
                }
                ++idx;
            }
            if (idx < vsize) {
                if (vals[idx].IsNullptr()) {
                    currlayer.emplace_back(nullptr);
                } else {
                    Node* r = new Node(vals[idx].vali);
                    parent->right = r;
                    currlayer.emplace_back(r);
                }
                ++idx;
            }
        }
        lastlayer = currlayer;
    }

    return root;
}
struct NodeAutoReleaser {
    unordered_set<Node*> nodes;
    NodeAutoReleaser(Node* root) { Append(root); }
    NodeAutoReleaser(Node* root1, Node* root2) { Append(root1), Append(root2); }
    void Append(Node* root) {
        queue<Node*> q;
        if (root != nullptr) q.emplace(root);
        while (!q.empty()) {
            root = q.front();
            q.pop();
            nodes.emplace(root);
            if (root->left) q.emplace(root->left);
            if (root->right) q.emplace(root->right);
        }
    }
    ~NodeAutoReleaser() {
        for (auto it : nodes) delete it;
        nodes.clear();
    }
};
vector<ComplexVal> LinerTree2vals(Node* root) {
    vector<ComplexVal> ret;
    queue<Node*> q;
    if (root) q.emplace(root);
    while (!q.empty()) {
        int qsize = q.size();
        for (int qi = 0; qi < qsize; ++qi) {
            root = q.front();
            q.pop();
            ret.emplace_back(root->val);
            if (qi == qsize - 1) ret.emplace_back(ComplexVal(null));
            if (root->left) q.emplace(root->left);
            if (root->right) q.emplace(root->right);
        }
    }

    return ret;
}
void test(const vector<ComplexVal>& nodevals, const vector<ComplexVal>& expectvals) {
    save4print(nodevals);
    Node* root = ConstructLinerTree(nodevals);
    NodeAutoReleaser _(root);
    Solution so;

    auto ret = so.connect(root);
    auto retvals = LinerTree2vals(ret);
    assert_eq_ret(expectvals, retvals);
}

int main() {
    test({1, 2, 3, 4, 5, null, 7}, {1, LTEND, 2, 3, LTEND, 4, 5, 7, LTEND});
    test({}, {});
    return 0;
}
