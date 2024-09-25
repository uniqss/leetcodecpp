#include "../inc.h"

class MyHashMap {
   public:
    MyHashMap() {}

    void put(int key, int value) {}

    int get(int key) {}

    void remove(int key) {}
};

void test(const vector<string>& ops, const vector<vector<int>>& params,
          const vector<ComplexVal>& expect) {
    vector<ComplexVal> ret;
    shared_ptr<MyHashMap> m = nullptr;
    for (int i = 0; i < ops.size(); ++i) {
        const auto& op = ops[i];
        const auto& parami = params[i];
        if (op == "MyHashMap") {
            m = make_shared<MyHashMap>();
        } else if (op == "put") {
            m->put(parami[0], parami[1]);
        } else if (op == "get") {
            ret.emplace_back(m->get(parami[0]));
            continue;
        } else if (op == "remove") {
            m->remove(parami[0]);
        } else {
            assert_retnone(false);
        }
        ret.emplace_back(null);
    }
    assert_eq_ret(expect, ret);
}

int main() {
    test({"MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"},
         {
             {},
             {1, 1},
             {2, 2},
             {1},
             {3},
             {2, 1},
             {2},
             {2},
             {2},
         },
         {null, null, null, 1, -1, null, 1, null, -1});
    return 0;
}
