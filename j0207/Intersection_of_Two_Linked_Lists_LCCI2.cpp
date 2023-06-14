#include "../inc.h"

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        int na = 0, nb = 0;
        ListNode *tmp = headA;
        while (tmp != nullptr) {
            tmp = tmp->next;
            ++na;
        }
        tmp = headB;
        while (tmp != nullptr) {
            ++nb;
            tmp = tmp->next;
        }
        int nmin = min(na, nb);
        while (na > nmin) {
            --na;
            headA = headA->next;
        }
        while (nb > nmin) {
            --nb;
            headB = headB->next;
        }
        while (headA != nullptr && headB != nullptr) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};

void test(const vector<int> &va, const vector<int> &vb, int expect) {
    auto la = constructList(va);
    auto lb = constructList(vb);
    ListAutoReleaser _(la, lb);
    ListNode *pa = la, *pb = lb;
    while (pa != nullptr && pa->next != nullptr && pa->next->val != expect) pa = pa->next;
    while (pb != nullptr && pb->next != nullptr && pb->next->val != expect) pb = pb->next;
    pb->next = pa->next;

    Solution so;
    auto ret = so.getIntersectionNode(la, lb);
    if (ret != nullptr && ret->val == expect) {
        print("ok");
    } else {
        print("not ok");
        print(va);
        print(vb);
        print(expect);
        print(ret->val);
        print();
    }
}

int main() {
    test({4, 1, 8, 4, 5}, {5, 0, 1, 8, 4, 5}, 8);
    return 0;
}
