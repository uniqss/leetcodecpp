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
    int kthToLast(ListNode* head, int k) {
        /*
        1 2 3 4 5 null   2
        h   f
              h   f
        */
        if (head == nullptr) return 0;
        ListNode* fast = head;
        for (int i = 0; i < k; ++i) {
            if (fast == nullptr) return 0;
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            head = head->next;
        }
        return head ? head->val : 0;
    }
};

void test(const vector<int>& vi, int k, int expect) {
    save4print(vi, k);
    auto list = constructList(vi);
    auto ret = Solution().kthToLast(list, k);
    assert_eq_ret(expect, ret);
    releaseLinkedList(list);
}

int main() {
    test({1, 2, 3, 4, 5}, 2, 4);
    return 0;
}
