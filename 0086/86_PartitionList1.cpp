#include "../inc.h"

class Solution {
   public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *headl = nullptr, *headr = nullptr, *l = nullptr, *r = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            if (head->val < x) {
                if (l != nullptr) l->next = head;
                l = head;
                if (headl == nullptr) headl = l;
                l->next = nullptr;
            } else {
                if (r != nullptr) r->next = head;
                r = head;
                if (headr == nullptr) headr = r;
                r->next = nullptr;
            }
            head = next;
        }

        if (headl == nullptr) return headr;
        l->next = headr;
        return headl;
    }
};

void test(const vector<int>& listvals, int x, const vector<int>& expectvals) {
    save4print(listvals);
    save4print(x);
    ListNode* head = constructList(listvals);
    Solution so;
    auto ret = so.partition(head, x);
    ListAutoReleaser _(head, ret);
    auto retvals = list2vals(ret);
    assert_eq_ret(expectvals, retvals);
}

int main() {
    test({1, 4, 3, 2, 5, 2}, 3, {1, 2, 2, 4, 3, 5});
    test({2, 1}, 2, {1, 2});
    return 0;
}
