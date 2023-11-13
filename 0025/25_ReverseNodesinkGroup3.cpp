#include "../inc.h"

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k <= 1) return head;
        ListNode ofake(0, head);
        ListNode* fake = &ofake;
        ListNode *kprev = fake, *knext = nullptr;
        ListNode *kleft = nullptr, *kright = nullptr;
        ListNode* loop = nullptr;
        while (true) {
            loop = kprev;
            kleft = loop->next;
            for (int i = 0; i < k; ++i) {
                if (loop == nullptr || loop->next == nullptr) return fake->next;
                loop = loop->next;
            }
            kright = loop;
            knext = loop->next;

            // reverse k
            ListNode *prev = kleft, *curr = prev->next;
            while (curr != knext) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            kprev->next = kright;
            kleft->next = knext;
            kprev = kleft;
        }
        return nullptr;
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
