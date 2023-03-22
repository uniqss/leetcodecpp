#include "../inc.h"

class Solution {
   public:
    ListNode* partition(ListNode* head, int x) {
        ListNode fake1, fake2;
        ListNode *tail1 = &fake1, *tail2 = &fake2;
        while (head != nullptr) {
            if (head->val < x) {
                tail1->next = head;
                tail1 = tail1->next;
            } else {
                tail2->next = head;
                tail2 = tail2->next;
            }
            ListNode* next = head->next;
            head->next = nullptr;
            head = next;
        }
        tail1->next = fake2.next;
        return fake1.next;
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
