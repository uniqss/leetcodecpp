#include "../inc.h"

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode fake, *prev = &fake;
        while (list1 != nullptr || list2 != nullptr) {
            if (list1 == nullptr) {
                prev->next = list2;
                break;
            }
            if (list2 == nullptr) {
                prev->next = list1;
                break;
            }
            if (list1->val < list2->val) {
                prev->next = list1;
                list1 = list1->next;
            } else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }

        return fake.next;
    }
};

void test(const std::vector<int>& v1, const std::vector<int>& v2, const std::vector<int>& expect) {
    save4print(v1);
    save4print(v2);
    ListNode *head1 = constructList(v1), *head2 = constructList(v2);
    Solution s;
    ListNode* ret = s.mergeTwoLists(head1, head2);
    auto retval = list2vals(ret);
    assert_eq_ret(expect, retval);
    ListAutoReleaser _(head1, head2, ret);
}

int main() {
    test({1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4});
    test({}, {}, {});
    test({}, {0}, {0});

    return 0;
}
