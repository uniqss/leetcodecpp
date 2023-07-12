#include "../inc.h"

class TreeAncestor {
    vector<int> parents;

   public:
    TreeAncestor(int n, vector<int>& parent) { parents = parent; }

    int getKthAncestor(int node, int k) {
        node = parents[node];
        if (node < 0) return node;
        while (--k > 0) {
            node = parents[node];
            if (node < 0) return node;
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

void test(const vector<string>& ops, const vector<vector<int>>& params, const vector<ComplexVal>& expect) {
    unique_ptr<TreeAncestor> p = nullptr;
    vector<ComplexVal> ret;
    for (size_t i = 0; i < ops.size(); i++) {
        auto& op = ops[i];
        auto param = params[i];
        if (op == "TreeAncestor") {
            p = make_unique<TreeAncestor>(param.size(), param);
            ret.push_back(null);
        } else {
            auto curr = p->getKthAncestor(param[0], param[1]);
            ret.push_back(curr);
        }
    }
    if (expect == ret) {
        print("ok");
    } else {
        print("not ok");
        print(ops);
        print(params);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({"TreeAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor"},
         {{-1, 0, 0, 1, 2}, {3, 5}, {3, 2}, {2, 2}, {0, 2}, {2, 1}}, {null, -1, 0, -1, -1, 0});
    test({"TreeAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor"},
         {{-1, 0, 0, 0, 3}, {1, 5}, {3, 2}, {0, 1}, {3, 1}, {3, 5}}, {null, -1, -1, -1, 0, -1});
    test({"TreeAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor"},
         {{-1, 0, 0, 1, 1, 2, 2}, {3, 1}, {5, 2}, {6, 3}}, {null, 1, 0, -1});
    return 0;
}
