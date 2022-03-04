#include "../inc.h"

/*
BFS 经典算法：(JAVA)
List<Integer> values = new ArrayList<>();
Queue<Node> queue = new LinkedList<>();
queue.add(root);
while (!queue.isEmpty()) {
    Node nextNode = queue.remove();
    values.add(nextNode.val);
    for (Node child : nextNode.children) {
        queue.add(child);
    }
}
BFS 经典算法：(CPP)
vector<int> ret;
queue<Node*> queue;
queue.push(root);
while(!queue.empty()){
    Node* curr = queue.front(); queue.pop();
    ret.emplace_back(curr->val);
    for (auto child : curr->children){
        queue.push(child);
    }
}
*/
// queue 我想出来的最原始的办法，需要两个queue不停的换来换去，一层换一把，有点浪费。事实上可以记一下queue的数量利用在queue尾加节点同时queue头出节点互不影响的特性
class Solution {
   public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        queue<Node*> parents;
        parents.push(root);
        vector<vector<int>> ret;
        while (!parents.empty()) {
            ret.resize(ret.size() + 1);
            vector<int>& children_val = ret[ret.size() - 1];
            queue<Node*> curr_layer;
            while (!parents.empty()) {
                Node* node = parents.front();
                parents.pop();
                children_val.emplace_back(node->val);
                for_each(node->children.begin(), node->children.end(), [&](Node* child) { curr_layer.push(child); });
            }

            parents = curr_layer;
        }

        return ret;
    }
};

void test(const vector<ComplexVal>& vals, const vector<vector<int>>& expect) {
    pvcomplex(vals);
    Node* root = constructNArrayTree(vals);
    pNArrayTree(root);
    Solution so;
    auto ret = so.levelOrder(root);
    if (ret != expect) {
        praw("not ok");
        pvcomplex(vals);
        pvvraw(expect);
        pvvraw(ret);
    } else {
        praw("ok.");
    }
}

int main() {
    test({1, null, 3, 2, 4, null, 5, 6}, {{1}, {3, 2, 4}, {5, 6}});
    test({1, null, 2, 3, 4, 5, null, null, 6, 7, null, 8, null, 9, 10, null, null, 11, null, 12, null, 13, null, null, 14}, {{1}, {2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13}, {14}});
    return 0;
}
