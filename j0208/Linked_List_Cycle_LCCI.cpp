#include "../inc.h"

class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {}
};

void test(const vector<int> &vi, int pos, int expect) {
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
    if (posret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(vi);
        print(pos);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({3, 2, 0, -4}, 1, 1);
    return 0;
}
