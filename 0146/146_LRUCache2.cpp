#include "../inc.h"

struct DLinkedNode {
    int key = 0;
    int value = 0;
    DLinkedNode* prev = nullptr;
    DLinkedNode* next = nullptr;
};
void RemoveNode(DLinkedNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}
void AddToHead(DLinkedNode* head, DLinkedNode* node) {
    head->next->prev = node;
    node->prev = head;
    node->next = head->next;
    head->next = node;
}
void MoveToHead(DLinkedNode* head, DLinkedNode* node) {
    RemoveNode(node);
    AddToHead(head, node);
}
class LRUCache {
    int size;
    int cap;
    unordered_map<int, DLinkedNode*> k2node;
    DLinkedNode *head, *tail;

   public:
    LRUCache(int capacity) : size(0), cap(capacity) {
        head = new DLinkedNode(), tail = new DLinkedNode();
        head->next = tail, tail->prev = head;
    }

    int get(int key) {
        if (k2node.count(key) == 0) return -1;
        DLinkedNode* node = k2node[key];
        int ret = node->value;
        MoveToHead(head, node);
        return ret;
    }

    void put(int key, int value) {
        auto it = k2node.find(key);
        if (it != k2node.end()) {
            it->second->value = value;
            MoveToHead(head, it->second);
        } else {
            DLinkedNode* node = new DLinkedNode();
            node->value = value;
            node->key = key;
            AddToHead(head, node);
            k2node[key] = node;
            if (++size > cap) {
                --size;
                k2node.erase(tail->prev->key);
                RemoveNode(tail->prev);
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
