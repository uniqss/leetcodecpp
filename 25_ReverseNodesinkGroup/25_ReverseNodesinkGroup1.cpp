#include "../stl.h"

/*
prev=>n1=>...=>nk(=>savedNext)
    get k elements(n1...nk). if not enough, just break.
        savedNext = nk->next
        n1 = prev->next

        // reverst n1...nk
        nnext = n1->next
        ncurr = n1
        // reverse n1...nk:   n1=>n2...nk_1=>nk    to    n1<=n2...nk_1<=nk
            nSavedNext = nnext->next
            nnext->next = ncurr
            ncurr = nnext
            nnext = nsavedNext
        prev->next = nk
        n1->next=savedNext
        prev = n1
*/

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode tmp;
        tmp.next = head;
        ListNode* prev = &tmp;
        ListNode* n1 = nullptr;
        ListNode* nk = nullptr;
        ListNode* curr = head;
        while (true) {
            int nCount = 0;
            while (nCount < k && curr != nullptr) {
                nk = curr;
                curr = curr->next;
                ++nCount;
            }
            if (nCount == k) {
                // reverse n1...nk
                ListNode* savedNext = nk->next;
                n1 = prev->next;
                ListNode* nnext = n1->next;
                ListNode* ncurr = n1;
                while (ncurr != nk) {
                    ListNode* nSavedNext = nnext->next;
                    nnext->next = ncurr;
                    ncurr = nnext;
                    nnext = nSavedNext;
                }

                prev->next = nk;
                n1->next = savedNext;
                prev = n1;
            } else {
                break;
            }
        }
        return tmp.next;
    }
};

void test(const std::vector<int>& vi, int k) {
    ListNode* head = nullptr;
    Solution s;
    ListNode* ret = nullptr;

    head = constructList(vi);
    pLinkedList(head);
    ret = s.reverseKGroup(head, k);
    pLinkedList(ret);
    releaseLinkedList(ret);
}

int main(int argc, char const* argv[]) {
    test({1, 2, 3, 4, 5}, 2);
    test({1, 2, 3, 4, 5}, 3);
    test({1, 2, 3, 4, 5}, 1);
    test({1, 2}, 2);
    test({1}, 1);
    return 0;
}
