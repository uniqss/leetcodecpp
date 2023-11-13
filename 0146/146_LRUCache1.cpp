#include "../inc.h"

/*
水不过去，会超时
*/
class LRUCache {
    struct Element {
        int key;
        int value;
    };
    list<Element*> elist;
    unordered_map<int, Element*> k2element;
    int cap = 0;

   public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        int ret = -1;
        auto it = k2element.find(key);
        if (it != k2element.end()) {
            Element* e = it->second;
            ret = e->value;
            if (elist.size() > 1 && e != elist.front()) {
                elist.remove(e);
                elist.push_front(e);
            }
        }
        return ret;
    }

    void put(int key, int value) {
        auto it = k2element.find(key);
        if (it != k2element.end()) {
            Element* e = it->second;
            e->value = value;
            if (elist.size() > 1 && e != elist.front()) {
                elist.remove(e);
                elist.push_front(e);
            }
        } else {
            Element* e = new Element();
            e->key = key;
            e->value = value;
            elist.push_front(e);
            k2element[key] = e;
            if ((int)elist.size() > cap) {
                Element* last = elist.back();
                k2element.erase(last->key);
                elist.pop_back();
                delete last;
            }
        }
    }
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
