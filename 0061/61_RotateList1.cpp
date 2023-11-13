#include "../inc.h"

class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        // 1, 2, 3, 4, 5    2
        // 4, 5, 1, 2, 3
        if (head == nullptr || head->next == nullptr || k <= 0) return head;
        int nodesize = 0;
        ListNode *curr = head, *tail = head;
        while (curr != nullptr) {
            ++nodesize;
            if (curr->next == nullptr) tail = curr;
            curr = curr->next;
        }
        k = k % nodesize;
        k = (nodesize - k) % nodesize;
        if (k == 0) return head;
        ListNode* prevrhead = head;
        for (int i = 0; i < k - 1; ++i) {
            prevrhead = prevrhead->next;
        }
        ListNode* rhead = prevrhead->next;
        prevrhead->next = nullptr;
        tail->next = head;
        return rhead;
    }
};

void test(const vector<int>& listvals, int k, const vector<int>& expectvals) {
    save4print(listvals);
    save4print(k);
    ListNode* head = constructList(listvals);
    Solution so;
    auto ret = so.rotateRight(head, k);
    ListAutoReleaser _(head, ret);
    auto retvals = list2vals(ret);
    assert_eq_ret(expectvals, retvals);
}

int main() {
    test({1, 2}, 1, {2, 1});
    test({1, 2, 3, 4, 5}, 2, {4, 5, 1, 2, 3});
    test({0, 1, 2}, 4, {2, 0, 1});
    return 0;
}
