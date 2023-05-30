#include "../inc.h"


class Solution {
   public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {}
};

void test(const vector<int>& vala, const vector<int>& valb, int skipa, int skipb, int expect) {
    Solution so;
    ListNode* heada = constructList(vala);
    ListNode* headb = constructList(valb);
    ListAutoReleaser _a(heada), _b(headb);

    if (expect > 0) {
        ListNode *preva = heada, *prevb = headb;
        for (int i = 0; i < skipa - 1; i++) preva = preva->next;
        for (int i = 0; i < skipb - 1; i++) prevb = prevb->next;
        prevb->next = preva->next;
    }

    auto ret = so.getIntersectionNode(heada, headb);
    int retval = ret ? ret->val : 0;
    if (retval == expect) {
        print("ok");
    } else {
        print("not ok");
        print(vala);
        print(valb);
        print(expect);
        print(retval);
    }
}

int main() {
    test({4, 1, 8, 4, 5}, {5, 6, 1, 8, 4, 5}, 2, 3, 8);
    test({1, 9, 1, 2, 4}, {3, 2, 4}, 3, 1, 2);
    test({2, 6, 4}, {1, 5}, 3, 2, 0);
    return 0;
}
