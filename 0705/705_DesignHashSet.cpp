#include "../inc.h"

class MyHashSet {
   public:
    MyHashSet() {}

    void add(int key) {}

    void remove(int key) {}

    bool contains(int key) {}
};

void test(vector<string>&& ops, vector<vector<int>>&& params, const vector<ComplexVal>& expect) {
    vector<ComplexVal> ret;
    shared_ptr<MyHashSet> hs = nullptr;
    for (int i = 0; i < ops.size(); ++i) {
        const auto& op = ops[i];

        if (op == "MyHashSet") {
            hs = make_shared<MyHashSet>();
            ret.emplace_back(null);
        } else if (op == "add") {
            hs->add(params[i][0]);
            ret.emplace_back(null);
        } else if (op == "remove") {
            hs->add(params[i][0]);
            ret.emplace_back(null);
        } else if (op == "contains") {
            ret.emplace_back(hs->contains(params[i][0]));
        }
    }
    assert_eq_ret(expect, ret);
}

int main() {
    test({"MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove",
          "contains"},
         {{}, {1}, {2}, {1}, {3}, {2}, {2}, {2}, {2}},
         {null, null, null, true, false, null, true, null, false});
    return 0;
}
