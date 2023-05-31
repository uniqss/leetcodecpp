#include "../inc.h"


class Solution {
   public:
    bool isPalindrome(ListNode* head) {
        vector<int> vi;
        while (head != nullptr) {
            vi.emplace_back(head->val);
            head = head->next;
        }
        auto vsize = vi.size();
        for (size_t i = 0; i < vsize / 2; i++) {
            if (vi[i] != vi[vsize - i - 1]) return false;
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
    test({1, 2, 2, 1}, true);
    test({1, 2}, false);
    test({1, 2, 1}, true);
    return 0;
}
