#include "../inc.h"

// 最简单直接的解法，不过会超出时间限制，50000个节点的时候，
class TreeAncestor {
    unordered_map<int, int> parents;

   public:
    TreeAncestor(int n, vector<int>& parent) {
        for (int i = 0; i < n; ++i) parents[i] = parent[i];
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i < k; ++i) {
            if (parents.count(node) == 0) return -1;
            node = parents[node];
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

void test(const vector<string>& ops, const vector<vector<ComplexVal>>&& params,
          const vector<ComplexVal>& expect) {
    shared_ptr<TreeAncestor> ta = nullptr;
    vector<ComplexVal> ret;
    for (int i = 0; i < ops.size(); ++i) {
        const string& op = ops[i];
        const auto& param = params[i];
        if (op == "TreeAncestor") {
            auto vi = param[1].tovi();
            ta = make_shared<TreeAncestor>(param[0].vali, vi);
            ret.emplace_back(null);
        } else if (op == "getKthAncestor") {
            auto curr = ta->getKthAncestor(param[0].vali, param[1].vali);
            ret.emplace_back(curr);
        }
    }
    assert_eq_ret(expect, ret);
}

int main() {
    test({"TreeAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor"},
         {{7, {-1, 0, 0, 1, 1, 2, 2}}, {3, 1}, {5, 2}, {6, 3}}, {null, 1, 0, -1});
    return 0;
}
