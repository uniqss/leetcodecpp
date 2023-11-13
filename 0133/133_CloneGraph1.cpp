#include "../helpers/stl.h"
#include "../helpers/uassert.h"
#include "../helpers/UnDirectedGraphHelper.h"

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        queue<Node*> q;
        Node *oldnode = node, *newnode = nullptr;
        unordered_set<Node*> vis;
        unordered_map<Node*, Node*> old2new;
        if (node) q.emplace(node), vis.emplace(node);
        while (!q.empty()) {
            node = q.front(), q.pop();
            Node* currnode = new Node(node->val);
            if (newnode == nullptr) newnode = currnode;
            old2new[node] = currnode;
            for (auto n : node->neighbors) {
                if (vis.count(n) == 0) vis.emplace(n), q.emplace(n);
            }
        }
        vis.clear();
        q.emplace(oldnode), vis.emplace(oldnode);
        while (!q.empty()) {
            node = q.front(), q.pop();
            Node* currnode = old2new[node];
            for (auto n : node->neighbors) {
                currnode->neighbors.emplace_back(old2new[n]);
                if (vis.count(n) == 0) vis.emplace(n), q.emplace(n);
            }
        }
        return newnode;
    }
};

void test(const vector<vector<int>>& adjlist, const vector<vector<int>> expect) {
    save4print(adjlist);
    Node* node = ConstructUnDirectedGraph(adjlist);
    auto ret = Solution().cloneGraph(node);
    auto retvals = node2vals(ret);
    NodeAutoReleaser _(node, ret);
    assert_eq_ret(expect, retvals);
}

int main() {
    test({{2, 4}, {1, 3}, {2, 4}, {1, 3}}, {{2, 4}, {1, 3}, {2, 4}, {1, 3}});
    test({{}}, {{}});
    test({}, {});
    return 0;
}
