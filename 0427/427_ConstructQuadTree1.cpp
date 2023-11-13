#include "../helpers/stl.h"
#include "../helpers/complexval.h"
#include "../helpers/uassert.h"
#include "../helpers/quadtreehelper.h"

class Solution {
   public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        Node* root = helper(grid, 0, 0, n);
        mergeup(root);
        return root;
    }
    void mergeup(Node* root) {
        if (root == nullptr) return;
        if (root->isLeaf) return;
        mergeup(root->topLeft);
        mergeup(root->topRight);
        mergeup(root->bottomLeft);
        mergeup(root->bottomRight);
        if (root->topLeft == nullptr || root->topRight == nullptr || root->bottomLeft == nullptr ||
            root->bottomRight == nullptr)
            return;
        if (!root->topLeft->isLeaf || !root->topRight->isLeaf || !root->bottomLeft->isLeaf ||
            !root->bottomRight->isLeaf)
            return;
        if (root->topLeft->val == root->topRight->val && root->topLeft->val == root->bottomLeft->val &&
            root->topLeft->val == root->bottomRight->val) {
            root->val = root->topLeft->val;
            root->isLeaf = true;
            delete root->topLeft, delete root->topRight, delete root->bottomLeft, delete root->bottomRight;
            root->topLeft = nullptr, root->topRight = nullptr, root->bottomLeft = nullptr, root->bottomRight = nullptr;
        }
    }
    Node* helper(vector<vector<int>>& grid, int x, int y, int edge) {
        if (edge <= 0) return nullptr;
        if (edge == 1) {
            Node* curr = new Node(grid[x][y], true);
            return curr;
        }
        Node* fake = new Node(1, false);
        edge /= 2;
        fake->topLeft = helper(grid, x, y, edge);
        fake->topRight = helper(grid, x, y + edge, edge);
        fake->bottomLeft = helper(grid, x + edge, y, edge);
        fake->bottomRight = helper(grid, x + edge, y + edge, edge);
        return fake;
    }
};

void test(vector<vector<int>>&& grid, const vector<ComplexVal>& expect) {
    save4print(grid);
    Node* ret = Solution().construct(grid);
    QuadTreeAutoReleaser _(ret);
    assert_eq_ret(expect, quadtree_node2vals(ret));
}

int main() {
    test({{0, 1}, {1, 0}}, {{0, 1}, {1, 0}, {1, 1}, {1, 1}, {1, 0}});
    test({{1, 1, 1, 1, 0, 0, 0, 0},
          {1, 1, 1, 1, 0, 0, 0, 0},
          {1, 1, 1, 1, 1, 1, 1, 1},
          {1, 1, 1, 1, 1, 1, 1, 1},
          {1, 1, 1, 1, 0, 0, 0, 0},
          {1, 1, 1, 1, 0, 0, 0, 0},
          {1, 1, 1, 1, 0, 0, 0, 0},
          {1, 1, 1, 1, 0, 0, 0, 0}},
         {{0, 1}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, null, null, null, null, {1, 0}, {1, 0}, {1, 1}, {1, 1}});
    return 0;
}
