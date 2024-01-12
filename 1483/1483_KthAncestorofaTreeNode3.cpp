#include "../inc.h"

class TreeAncestor {
    // vector<parent, depth>
    vector<pair<int, int>> v2pd;

   public:
    TreeAncestor(int n, vector<int>& parent) {
        v2pd.resize(n, {-1, -1});
        for (int v = 0; v < n; ++v) {
            int p = parent[v];
            int d = 1;
            if (p >= 0 && v2pd[p].second > 0) {
                d = v2pd[p].second + 1;
            }
            v2pd[v] = {p, d};
        }
    }

    int getKthAncestor(int node, int k) {
        int d = v2pd[node].second;
        if (d == -1 || d < k) return -1;
        for (int i = 0; i < k; ++i) {
            node = v2pd[node].first;
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
    test({"TreeAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor",
          "getKthAncestor"},
         {{5, {-1, 0, 0, 0, 3}}, {1, 5}, {3, 2}, {0, 1}, {3, 1}, {3, 5}},
         {null, -1, -1, -1, 0, -1});
    test({"TreeAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor"},
         {{7, {-1, 0, 0, 1, 1, 2, 2}}, {3, 1}, {5, 2}, {6, 3}}, {null, 1, 0, -1});
    return 0;
}
