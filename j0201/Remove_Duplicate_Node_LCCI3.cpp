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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* prev = head;
        while (prev->next != nullptr) {
            ListNode* find = head;
            while (find != nullptr && find != prev->next && find->val != prev->next->val)
                find = find->next;
            if (find != nullptr && find != prev->next && find->val == prev->next->val) {
                ListNode* next = prev->next->next;
                delete prev->next;
                prev->next = next;
            } else {
                prev = prev->next;
            }
        }
        return head;
    }
};

void test(const vector<int>& vi, const vector<int>& expect) {
    save4print(vi);
    auto list = constructList(vi);
    auto ret = Solution().removeDuplicateNodes(list);
    auto retval = list2vals(ret);
    assert_eq_ret(expect, retval);
    releaseLinkedList(list);
}

int main() {
    test({1, 2, 3, 3, 2, 1}, {1, 2, 3});
    test({1, 1, 1, 1, 2}, {1, 2});
    return 0;
}
