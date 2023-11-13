#include "../inc.h"

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode fake(0, head), *prev = &fake, *l, *r, *next;
        auto revlist = [](ListNode* head) -> ListNode* {
            ListNode *prev = nullptr, *curr = head, *next;
            while (curr != nullptr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        };
        while (true) {
            l = prev->next, r = prev;
            for (int i = 0; i < k && r != nullptr; ++i) r = r->next;
            if (r == nullptr) break;
            next = r->next;
            r->next = nullptr;
            prev->next = revlist(prev->next);
            prev = l;
            l->next = next;
        }

        return fake.next;
    }
};

void test(const std::vector<int>& vi, int k, const vector<int>& expect) {
    save4print(vi, k);
    ListNode *head = nullptr, *ret = nullptr;
    head = constructList(vi);
    ListAutoReleaser _(head);
    ret = Solution().reverseKGroup(head, k);
    _.Append(ret);
    assert_eq_ret(expect, list2vals(ret));
}

int main(int argc, char const* argv[]) {
    test({1, 2, 3, 4, 5, 6}, 2, {2, 1, 4, 3, 6, 5});
    test({1, 2, 3, 4, 5}, 2, {2, 1, 4, 3, 5});
    test({1, 2, 3, 4, 5}, 3, {3, 2, 1, 4, 5});
    test({1, 2, 3, 4, 5}, 1, {1, 2, 3, 4, 5});
    test({1, 2}, 2, {2, 1});
    test({1}, 1, {1});
    return 0;
}
