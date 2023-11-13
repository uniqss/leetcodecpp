#include "../inc.h"

class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 这种题目要想速过一定要画图。另外要注意范围， 1 <= left <= right <= n，所以不能处理left - 1和right + 1
        // 1 2 3 4 5   2 4
        //  l   r
        // 1 4 3 2 5
        if (left >= right) return head;
        ListNode fake(0, head), *prev = &fake, *curr = head, *lhead, *prevlhead;
        int idx = 0;
        while (curr != nullptr) {
            ++idx;
            ListNode* next = curr->next;
            if (idx == left) {
                prevlhead = prev;
                lhead = curr;
                prev = curr;
                curr = next;
            } else if (idx > left && idx < right) {
                curr->next = prev;
                prev = curr;
                curr = next;
            } else if (idx == right) {
                curr->next = prev;
                prevlhead->next = curr;
                lhead->next = next;
                prev = lhead;
                curr = next;
            } else {
                prev = curr;
                curr = next;
            }
        }
        return fake.next;
    }
};

void test(const vector<int>& listvals, int left, int right, const vector<int>& expectvals) {
    save4print(listvals);
    save4print(left);
    save4print(right);
    ListNode* head = constructList(listvals);
    Solution so;
    auto ret = so.reverseBetween(head, left, right);
    ListAutoReleaser _(head, ret);
    auto retvals = list2vals(ret);
    assert_eq_ret(expectvals, retvals);
}

int main() {
    test({1, 2, 3, 4, 5}, 2, 4, {1, 4, 3, 2, 5});
    test({5}, 1, 1, {5});
    return 0;
}