#include "../inc.h"

class Solution {
   public:
    ListNode* partition(ListNode* head, int x) {
        /*
        fake 2 3 5 1 null  3
             l  r c
        fake 2 1 3 5 null  3
               l r   c
        fake 8 3 5 1 null  3
           l r     c
        fake 1 8 3 5 null  3
             l r     c
        */
        if (head == nullptr || head->next == nullptr) return head;
        ListNode fake(0, head);
        ListNode* l = head->val < x ? head : &fake;
        ListNode* r = head;
        while (r != nullptr && r->val < x) r = r->next;
        if (r == nullptr) return fake.next;
        while (r->next != nullptr) {
            if (r->next->val < x) {
                ListNode* lnext = l->next;
                ListNode* rnext = r->next->next;
                r->next->next = lnext;
                l->next = r->next;
                r->next = rnext;
            } else {
                r = r->next;
            }
        }
        return fake.next;
    }
};

void test(const vector<int>& vi, int x) {
    auto l = constructList(vi);
    Solution so;
    auto ret = so.partition(l, x);
    auto retval = list2vals(ret);

    bool bok = true;
    do {
        if (retval.size() != vi.size()) {
            bok = false;
            break;
        }

        if (retval.empty()) break;

        bool less = retval[0] < x;
        for (size_t i = 1; i < retval.size() && bok; ++i) {
            if (retval[i] >= x) {
                if (less) {
                    less = false;
                }
            } else {
                if (!less) {
                    bok = false;
                }
            }
        }
    } while (false);

    if (bok) {
        print("ok");
    } else {
        print("not ok");
        print(vi);
        print(x);
        print(retval);
    }

    releaseLinkedList(ret);
}

int main() {
    test({1, 4, 3, 2, 5, 2}, 3);
    return 0;
}
