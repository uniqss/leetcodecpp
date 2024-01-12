#include "../inc.h"

// 终于过了，只是cpu很差
class TreeAncestor {
    vector<int> vp;
    vector<int> vp16;
    vector<int> vp256;
    vector<int> vp4096;

   public:
    TreeAncestor(int n, vector<int>& parent) {
        vector<vector<int>> children(n);
        for (int i = 0; i < n; ++i) {
            int p = parent[i];
            if (p >= 0) children[p].emplace_back(i);
        }
        vp = parent;
        vp16.resize(n, -1);
        vp256.resize(n, -1);
        vp4096.resize(n, -1);
        function<void(int, int, int, int, int)> dfs = [&](int curr, int start16, int start256,
                                                          int start4096, int depth) {
            if (depth % 16 == 0) {
                vp16[curr] = start16;
                start16 = curr;
                if (depth % 256 == 0) {
                    vp256[curr] = start256;
                    start256 = curr;
                    if (depth % 4096 == 0) {
                        vp4096[curr] = start4096;
                        start4096 = curr;
                    }
                }
            }
            for (int child : children[curr]) {
                dfs(child, start16, start256, start4096, depth + 1);
            }
        };
        dfs(0, 0, 0, 0, 1);
    }

    int getKthAncestor(int node, int k) {
        int i = 0;
        while (i < k) {
            if (k - i >= 4096 && vp4096[node] > 0) {
                i += 4096;
                node = vp4096[node];
                continue;
            }
            if (k - i >= 256 && vp256[node] > 0) {
                i += 256;
                node = vp256[node];
                continue;
            }
            if (k - i >= 16 && vp16[node] > 0) {
                i += 16;
                node = vp16[node];
                continue;
            }
            node = vp[node];
            if (node < 0) return -1;
            ++i;
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
