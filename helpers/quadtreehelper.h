#pragma once

#include "stl.h"
#include "complexval.h"
#include "uassert.h"

#ifndef null
#define null nullptr
#endif

// Definition for a QuadTree node.
class Node {
   public:
    bool val = false;
    bool isLeaf = false;
    Node* topLeft = nullptr;
    Node* topRight = nullptr;
    Node* bottomLeft = nullptr;
    Node* bottomRight = nullptr;

    Node() = default;
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

struct QuadTreeAutoReleaser {
    unordered_set<Node*> all_nodes;
    QuadTreeAutoReleaser() = default;
    QuadTreeAutoReleaser(Node* node) { Append(node); }
    QuadTreeAutoReleaser(Node* node1, Node* node2) { Append(node1), Append(node2); }
    QuadTreeAutoReleaser(Node* node1, Node* node2, Node* node3) { Append(node1), Append(node2), Append(node3); }
    void Append(Node* node) {
        queue<Node*> q;
        if (node) q.emplace(node);
        while (!q.empty()) {
            node = q.front(), q.pop();
            all_nodes.emplace(node);
            if (node->topLeft) q.emplace(node->topLeft);
            if (node->topRight) q.emplace(node->topRight);
            if (node->bottomLeft) q.emplace(node->bottomLeft);
            if (node->bottomRight) q.emplace(node->bottomRight);
        }
    }
};

vector<ComplexVal> quadtree_node2vals(Node* node) {
    vector<ComplexVal> ret;
    queue<Node*> q;
    if (node != nullptr) q.emplace(node);
    while (!q.empty()) {
        int qsize = q.size();
        for (int i = 0; i < qsize; ++i) {
            node = q.front(), q.pop();
            if (node == nullptr) {
                ret.emplace_back(nullptr);
                continue;
            }
            ret.emplace_back(ComplexVal(std::pair<int, int>(node->isLeaf, node->val)));
            q.emplace(node->topLeft);
            q.emplace(node->topRight);
            q.emplace(node->bottomLeft);
            q.emplace(node->bottomRight);
        }
    }
    while (!ret.empty() && ret.back() == nullptr) {
        ret.pop_back();
    }

    return ret;
}
