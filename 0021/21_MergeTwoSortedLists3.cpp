#include "../inc.h"

// 稍稍有一点取巧，稍稍有一点笨拙，但是彻底隔离了返回list与原来两个List之间串在一起的问题
class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode fake, *pre = &fake, *curr;
        while (list1 != nullptr || list2 != nullptr) {
            if (list2 == nullptr || (list1 != nullptr && list1->val < list2->val)) {
                curr = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                curr = new ListNode(list2->val);
                list2 = list2->next;
            }
            pre->next = curr;
            pre = pre->next;
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
