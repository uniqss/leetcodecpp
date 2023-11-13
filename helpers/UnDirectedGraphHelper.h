#pragma once

#include "stl.h"

class Node {
   public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

struct NodeAutoReleaser {
    unordered_set<Node*> nodes;
    NodeAutoReleaser(Node* node) { Append(node); }
    NodeAutoReleaser(Node* node1, Node* node2) { Append(node1), Append(node2); }
    ~NodeAutoReleaser() {
        for (auto n : nodes) delete n;
        nodes.clear();
    }
    void Append(Node* node) {
        unordered_set<Node*> vis;
        queue<Node*> q;
        if (node) q.emplace(node), vis.emplace(node);
        while (!q.empty()) {
            node = q.front(), q.pop();
            nodes.emplace(node);
            for (auto n : node->neighbors)
                if (n && vis.count(n) == 0) {
                    vis.emplace(n);
                    q.emplace(n);
                }
        }
    }
};

Node* ConstructUnDirectedGraph(const vector<vector<int>>& adjlist) {
    if (adjlist.empty()) return nullptr;
    Node* root = nullptr;
    vector<Node*> nodes;
    for (int i = 0; i < (int)adjlist.size(); ++i) {
        Node* node = new Node(i + 1);
        if (root == nullptr) root = node;
        nodes.emplace_back(node);
    }
    for (int i = 0; i < (int)adjlist.size(); ++i) {
        for (auto nidx : adjlist[i]) {
            nodes[i]->neighbors.emplace_back(nodes[nidx - 1]);
        }
    }
    return root;
}

vector<vector<int>> node2vals(Node* node) {
    vector<vector<int>> ret;
    if (node == nullptr) return ret;
    unordered_map<Node*, int> node2val;
    queue<Node*> q;
    unordered_set<Node*> vis;
    q.emplace(node), vis.emplace(node);
    Node* curr;
    int maxval = 0;
    while (!q.empty()) {
        curr = q.front(), q.pop();
        node2val[curr] = curr->val;
        maxval = max(maxval, curr->val);
        for (auto n : curr->neighbors) {
            if (vis.count(n) == 0) {
                q.emplace(n), vis.emplace(n);
            }
        }
    }
    ret.resize(maxval);
    vis.clear();
    q.emplace(node), vis.emplace(node);
    while (!q.empty()) {
        curr = q.front(), q.pop();
        for (auto n : curr->neighbors) {
            ret[node2val[curr] - 1].emplace_back(node2val[n]);
            if (vis.count(n) == 0) {
                q.emplace(n), vis.emplace(n);
            }
        }
    }

    return ret;
}
