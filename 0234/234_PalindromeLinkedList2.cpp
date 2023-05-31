#include "../inc.h"

// this is not safe, list's inner structure is broken
class Solution {
   public:
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode *curr = head, *prev = head;
        while (curr != nullptr) {
            curr = curr->next;
            ++len;
        }
        if (len == 1) return true;
        for (int i = 0; i < (len - 1) / 2; i++) {
            prev = prev->next;
        }
        ListNode *fprev = nullptr, *fcurr = prev->next, *next = nullptr;
        while (fcurr != nullptr) {
            next = fcurr->next;
            fcurr->next = fprev;
            fprev = fcurr;
            fcurr = next;
        }
        curr = head;
        next = fprev;
        while (next != nullptr) {
            if (curr->val != next->val) return false;
            next = next->next;
            curr = curr->next;
        }
        return true;
    }
};

void test(const vector<int>& headvals, bool expect) {
    ListNode* head = constructList(headvals);
    ListAutoReleaser _(head);
    Solution so;
    auto ret = so.isPalindrome(head);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(headvals);
        print(expect);
        print(ret);
    }
}

int main() {
    test({1, 2, 3, 1}, false);
    test({1, 2, 2, 1}, true);
    test({1, 2}, false);
    test({1, 2, 1}, true);
    test({1, 2, 2}, false);
    return 0;
}
