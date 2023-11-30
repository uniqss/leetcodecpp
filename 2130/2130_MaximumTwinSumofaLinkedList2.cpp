#include "../inc.h"

class Solution {
   public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head->next, *head1;
        auto reverseList = [](ListNode* head) {
            ListNode *prev = nullptr, *curr = head;
            while (curr != nullptr) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        };
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        head1 = slow->next;
        slow->next = nullptr;
        head1 = reverseList(head1);
        ListNode *curr1 = head, *curr2 = head1;
        int ret = 0;
        while (curr1 != nullptr) {
            ret = max(ret, curr1->val + curr2->val);
            curr1 = curr1->next, curr2 = curr2->next;
        }
        head1 = reverseList(head1);
        slow->next = head1;
        return ret;
    }
};

void test(const vector<int>& vals, int expect) {
    save4print(vals);
    auto head = constructList(vals);
    ListAutoReleaser _(head);
    auto ret = Solution().pairSum(head);
    assert_eq_ret(expect, ret);
}

int main() {
    test({5, 4, 2, 1}, 6);
    test({4, 2, 2, 3}, 7);
    test({1, 100000}, 100001);
    return 0;
}
