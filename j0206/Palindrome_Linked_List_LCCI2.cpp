#include "../inc.h"

class Solution {
   public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        auto reverseList = [](ListNode* head) {
            ListNode *prev = nullptr, *curr = head, *next;
            while (curr != nullptr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        };
        ListNode *slow = head, *fast = head->next;
        /*
         1 2 3 2 1 null
         s f
             s     f
         1 2 3 3 2 1 null
         s f
             s     f
        */
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        bool odd = fast == nullptr;
        ListNode* right = slow->next;
        slow->next = nullptr;
        ListNode* left = reverseList(head);
        if (odd) left = left->next;
        while (left != nullptr && right != nullptr) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};

void test(const vector<int>& vi, bool expect) {
    auto list = constructList(vi);
    ListAutoReleaser _(list);
    Solution so;
    auto ret = so.isPalindrome(list);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(vi);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({1, 2}, false);
    test({1, 2, 1}, true);
    test({1, 2, 2, 1}, true);
    test({0, 2, 2, 1}, false);
    return 0;
}
