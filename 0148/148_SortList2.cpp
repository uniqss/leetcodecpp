#include "../inc.h"

/*
此法甚经典
*/
class Solution {
   public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *slow = head, *fast = head->next->next;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* rhead = slow->next;
        slow->next = nullptr;
        ListNode *l = sortList(head), *r = sortList(rhead);
        return mergeList(l, r);
    }
    ListNode* mergeList(ListNode* l, ListNode* r) {
        ListNode fake, *prev = &fake;
        while (l != nullptr && r != nullptr) {
            if (l->val < r->val) {
                prev->next = l;
                l = l->next;
            } else {
                prev->next = r;
                r = r->next;
            }
            prev = prev->next;
        }
        if (l != nullptr) {
            prev->next = l;
        } else if (r != nullptr) {
            prev->next = r;
        }
        return fake.next;
    }
};

void test(vector<int>&& listvals, const vector<int>& expect) {
    save4print(listvals);
    auto head = constructList(listvals);
    ListAutoReleaser _(head);
    auto ret = Solution().sortList(head);
    _.Append(ret);
    assert_eq_ret(expect, list2vals(ret));
}

int main() {
    test({4, 2, 1, 3}, {1, 2, 3, 4});
    test({-1, 5, 3, 4, 0}, {-1, 0, 3, 4, 5});
    test({}, {});
    return 0;
}
