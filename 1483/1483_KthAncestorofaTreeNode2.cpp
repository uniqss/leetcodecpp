#include "../inc.h"

// 继续超时
class TreeAncestor {
    vector<unordered_map<int, int>> nkp;

   public:
    TreeAncestor(int n, vector<int>& parent) {
        vector<vector<int>> children(n);
        for (int i = 0; i < n; ++i) {
            if (parent[i] >= 0) children[parent[i]].emplace_back(i);
        }
        nkp.resize(n);
        function<void(int, int, int)> dfs = [&](int top, int curr, int k) {
            for (int child : children[curr]) {
                nkp[child][k + 1] = top;
                dfs(top, child, k + 1);
                dfs(child, child, 0);
            }
        };
        dfs(0, 0, 0);
    }

    int getKthAncestor(int node, int k) {
        if (nkp[node].count(k) == 0) return -1;
        return nkp[node][k];
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
