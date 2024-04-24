#include "../inc.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    void deleteNode(ListNode* node) {
        /*
        fk 1 2 3 null
        ps f
           ps  f
        fk 1 2 3 4 null
        ps f
           ps  f
        */
        if (node == nullptr || node->next == nullptr || node->next->next == nullptr) return;
        ListNode fake(0, node);
        ListNode *preSlow = &fake, *fast = node;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            preSlow = preSlow->next;
            fast = fast->next->next;
        }
        ListNode* next = preSlow->next->next;
        delete preSlow->next;
        preSlow->next = next;
    }
};

void test(const vector<int>& vi, const vector<int>& expect) {
    save4print(vi);
    auto l = constructList(vi);
    ListAutoReleaser _(l);
    if (vi.size() >= 2) {
        Solution().deleteNode(l->next);
    }
    auto ret = list2vals(l);
    assert_eq_ret(expect, ret);
}

int main() {
    test({4, 5, 1, 9}, {4, 1, 9});
    test({5}, {5});
    test({5, 6}, {5, 6});
    return 0;
}
