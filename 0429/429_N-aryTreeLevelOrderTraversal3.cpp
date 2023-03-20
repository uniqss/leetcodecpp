#include "../inc/inc.h"

template <class T, std::size_t N>
class AllocedPtrQueue {
    std::array<T*, N> ptrs_;
    size_t head_;
    size_t tail_;

   public:
    AllocedPtrQueue() : head_(0), tail_(0) {}
    bool push(T* ptr) {
        if ((tail_ + 1) % N == head_) return false;
        ptrs_[tail_] = ptr;
        tail_ = (tail_ + 1) % N;
        return true;
    }
    bool pop() {
        if (head_ == tail_) return false;
        head_ = (head_ + 1) % N;
        return true;
    }
    size_t size() const { return (tail_ + N - head_) % N; }
    bool empty() const { return head_ == tail_; }
    T* front() {
        if (head_ == tail_) return nullptr;
        return ptrs_[head_];
    }
    const T* front() const {
        if (head_ == tail_) return nullptr;
        return ptrs_[head_];
    }
};

// bfs 对2的优化，使用预分配内存和偏移避免频繁分配释放queue中元素
class Solution {
   public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;
        AllocedPtrQueue<Node, 10000> q;
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
    Node* root = constructNArrayTree(vals);
    Solution so;
    auto ret = so.levelOrder(root);
    if (ret != expect) {
        print("not ok");
        print(vals);
        print(root);
        print(expect);
        print(ret);
    } else {
        print("ok.");
    }
}

int main() {
    test({1, null, 3, 2, 4, null, 5, 6}, {{1}, {3, 2, 4}, {5, 6}});
    test({1, null, 2,    3,    4,  5,    null, null, 6,  7,    null, 8, null,
          9, 10,   null, null, 11, null, 12,   null, 13, null, null, 14},
         {{1}, {2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13}, {14}});
    return 0;
}
