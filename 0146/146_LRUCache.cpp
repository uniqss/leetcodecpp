#include "../inc.h"

class LRUCache {
   public:
    LRUCache(int capacity) {}

    int get(int key) {}

    void put(int key, int value) {}
};

void test(const vector<string>& ops, const vector<vector<int>>& params, const vector<ComplexVal>& expect) {
    save4print(ops, params);
    vector<ComplexVal> ret;
    unique_ptr<LRUCache> cache = nullptr;
    for (int i = 0; i < ops.size(); ++i) {
        const auto& op = ops[i];
        const auto& param = params[i];
        if (op == "LRUCache") {
            cache = std::make_unique<LRUCache>(param[0]);
            ret.emplace_back(null);
        } else if (op == "put") {
            cache->put(param[0], param[1]);
            ret.emplace_back(null);
        } else if (op == "get") {
            auto curr = cache->get(param[0]);
            ret.emplace_back(curr);
        }
    }
    assert_eq_ret(expect, ret);
}

int main() {
    test({"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"},
         {{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {4, 4}, {1}, {3}, {4}},
         {null, null, null, 1, null, -1, null, -1, 3, 4});
    return 0;
}
