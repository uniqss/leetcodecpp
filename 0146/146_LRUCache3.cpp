#include "../inc.h"

class LRUCache {
    struct CacheNode {
        CacheNode* prev = nullptr;
        CacheNode* next = nullptr;
        int key;
        int data;
    };
    unordered_map<int, CacheNode*> dict;
    CacheNode *head, *tail;
    int cap;
    void Add2Head(CacheNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void RemNodeFromList(CacheNode* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->next = nullptr, node->prev = nullptr;
    }

   public:
    LRUCache(int capacity) : head(new CacheNode()), tail(new CacheNode()), cap(capacity) {
        head->next = tail, tail->prev = head;
    }

    int get(int key) {
        auto it = dict.find(key);
        if (it == dict.end()) return -1;
        int ret = it->second->data;
        RemNodeFromList(it->second);
        Add2Head(it->second);
        return ret;
    }

    void put(int key, int value) {
        auto it = dict.find(key);
        if (it != dict.end()) {
            it->second->data = value;
            RemNodeFromList(it->second);
            Add2Head(it->second);
        } else {
            CacheNode* curr = new CacheNode();
            curr->key = key;
            curr->data = value;
            dict[key] = curr;
            Add2Head(curr);
            while (dict.size() > cap) {
                CacheNode* del = tail->prev;
                RemNodeFromList(del);
                dict.erase(del->key);
                delete del;
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
