#include "../helpers/stl.h"
#include "../helpers/complexval.h"
#include "../helpers/uassert.h"

#define null nullptr

class Node {
   public:
    int val;
    Node* next = nullptr;
    Node* random = nullptr;
    Node(int _val) : val(_val) {}
};

class Solution {
   public:
    Node* copyRandomList(Node* head) {}
};

Node* ConstructNode(const vector<vector<ComplexVal>>& vals) {
    Node fake(0), *prev = &fake;
    unordered_map<int, Node*> idx2node;
    for (int i = 0; i < vals.size(); ++i) {
        Node* curr = new Node(vals[i][0].vali);
        idx2node[i] = curr;
        prev->next = curr;
        prev = curr;
    }
    Node* curr = fake.next;
    for (int i = 0; i < vals.size(); ++i) {
        if (vals[i][1] == nullptr) {
        } else {
            curr->random = idx2node[vals[i][1].vali];
        }
        curr = curr->next;
    }
    return fake.next;
}

vector<vector<ComplexVal>> node2vals(Node* node) {
    vector<vector<ComplexVal>> ret;
    unordered_map<Node*, int> node2idx;
    int idx = 0;
    Node* curr = node;
    while (curr != nullptr) {
        ret.push_back({curr->val, nullptr});
        node2idx[curr] = idx++;
        curr = curr->next;
    }
    curr = node;
    idx = 0;
    while (curr != nullptr) {
        if (curr->random != nullptr) {
            ret[idx][1] = node2idx[curr->random];
        }
        ++idx;
        curr = curr->next;
    }

    return ret;
}

struct SharedNodeReleaseMgr {
    unordered_set<Node*> nodes;
    ~SharedNodeReleaseMgr() {
        for (auto node : nodes) delete node;
    }
};
SharedNodeReleaseMgr goSharedNodeReleaseMgr;
struct NodeAutoReleaser {
    NodeAutoReleaser(Node* head) {
        while (head != nullptr) {
            goSharedNodeReleaseMgr.nodes.emplace(head);
            head = head->next;
        }
    }
};

void test(const vector<vector<ComplexVal>>& vals) {
    auto expect = vals;
    Node* head = ConstructNode(vals);
    Solution so;
    auto ret = so.copyRandomList(head);
    NodeAutoReleaser _1(head), _2(ret);
    auto retvals = node2vals(ret);
    assert_eq_ret(expect, retvals);
}

int main() {
    test({{7, null}, {13, 0}, {11, 4}, {10, 2}, {1, 0}});
    test({{1, 1}, {2, 1}});
    return 0;
}