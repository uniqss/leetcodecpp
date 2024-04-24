#include "../inc.h"

/*
这样应该也是ok的，多了个fake头节点，然后归的时候就不用往后移一位了，fast直接归到fake位，slow/fast这个时候不可能相等
*/
class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode fake(0, head);
        ListNode *prev = &fake, *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                fast = prev;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};

void test(const vector<int> &vi, int pos, int expect) {
   save4print(vi, pos);
    auto l = constructList(vi);
    ListAutoReleaser _(l);
    ListNode *curr = l, *tail = l;
    while (tail->next != nullptr) tail = tail->next;
    for (int i = 0; i < pos; ++i) {
        curr = curr->next;
    }
    tail->next = curr;

    Solution so;
    auto ret = so.detectCycle(l);
    int posret = 0;
    curr = l;
    while (curr != nullptr) {
        if (curr == ret) break;
        curr = curr->next;
        ++posret;
        if (posret > vi.size()) break;
    }
    assert_eq_ret(expect, posret);
}

int main() {
    test({3, 2, 0, -4}, 1, 1);
    return 0;
}
