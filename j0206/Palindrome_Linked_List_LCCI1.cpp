#include "../inc.h"

class Solution {
   public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        vector<int> vi;
        while (head != nullptr) {
            vi.emplace_back(head->val);
            head = head->next;
        }
        auto vsize = vi.size();
        for (size_t i = 0; i < vsize / 2; ++i) {
            if (vi[i] != vi[vsize - i - 1]) return false;
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
