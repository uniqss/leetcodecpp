#include "../inc.h"

// 这个题目是shit，可以不用做，直接next
class Solution {
   public:
    void deleteNode(ListNode* node) {
        if (node->next != nullptr) {
            node->val = node->next->val;
            node->next = node->next->next;
        }
    }
};

void test(const vector<int>& vi, const vector<int>& expect) {
    auto l = constructList(vi);
    ListAutoReleaser _(l);
    Solution so;
    if (vi.size() >= 2) {
        so.deleteNode(l->next);
    }
    auto ret = list2vals(l);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(vi);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({4, 5, 1, 9}, {4, 1, 9});
    test({5}, {5});
    test({5, 6}, {5, 6});
    return 0;
}
