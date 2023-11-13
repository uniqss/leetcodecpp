#include "../inc.h"

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        int prevval = INT_MIN;
        ListNode fake(INT_MIN, head), *prev = &fake, *curr, *next;
        while (true) {
            if (prev == nullptr || prev->next == nullptr) break;
            curr = prev->next;
            while (curr->next != nullptr && curr->next->val == curr->val) {
                curr = curr->next;
            }
            if (prev->next != curr) {
                next = curr->next;
                curr = prev->next;
                while (curr != next) {
                    ListNode* tmp = curr->next;
                    delete curr;
                    curr = tmp;
                }
                prev->next = next;
            } else {
                prev = curr;
            }
        }

        return fake.next;
    }
};

void test(const vector<int>& listvals, const vector<int>& expectvals) {
    save4print(listvals);
    ListNode* head = constructList(listvals);
    Solution so;
    auto ret = so.deleteDuplicates(head);
    ListAutoReleaser _(ret);
    auto retvals = list2vals(ret);
    assert_eq_ret(expectvals, retvals);
}

int main() {
    test({1, 2, 3, 3, 4, 4, 5}, {1, 2, 5});
    test({1, 1, 1, 2, 3}, {2, 3});
    return 0;
}
