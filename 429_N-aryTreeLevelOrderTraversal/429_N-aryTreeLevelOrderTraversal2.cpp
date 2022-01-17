#include "../stl.h"

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
// class Solution {
//     public List<List<Integer>> levelOrder(Node root) {
//         List<List<Integer>> result = new ArrayList<>();
//         if (root == null) return result;
//         Queue<Node> queue = new LinkedList<>();
//         queue.add(root);
//         while (!queue.isEmpty()) {
//             List<Integer> level = new ArrayList<>();
//             int size = queue.size();
//             for (int i = 0; i < size; i++) {
//                 Node node = queue.poll();
//                 level.add(node.val);
//                 queue.addAll(node.children);
//             }
//             result.add(level);
//         }
//         return result;
//     }
// }
// bfs 这个算法很经典 只用一个queue 不用换来换去的浪费时间空间
// 事实上如果我们知道一层的最大节点数量，这里可以封装一个数据结构，用下标计算偏移，预先把内存分配完成，对非常高(层数非常深)的树性能会有显著提升(典型的空间换时间预分配思路)，参见3的实现
class Solution {
   public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            ret.resize(ret.size() + 1);
            vector<int>& layer = ret[ret.size() - 1];
            size_t qsize = q.size();
            for (size_t i = 0; i < qsize; ++i) {
                Node* node = q.front();
                q.pop();
                layer.push_back(node->val);
                std::for_each(node->children.begin(), node->children.end(), [&](Node* child) { q.push(child); });
            }
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
