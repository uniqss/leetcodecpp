#include "../inc.h"

class Solution {
   public:
    ListNode *reverseList(ListNode *head) { return helper(nullptr, head); }
    ListNode *helper(ListNode *prev, ListNode *curr) {
        if (curr == nullptr) return prev;
        ListNode *tmp = curr->next;
        curr->next = prev;
        return helper(curr, tmp);
    }
};

void test_vi(const vector<int> &vi, const vector<int> &expect) {
    Solution s;
    ListNode *head = nullptr;
    ListNode *ret = nullptr;

    head = constructList(vi);
    ret = s.reverseList(head);
    // pLinkedList(ret);
    auto retval = list2vals(ret);
    if (retval == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(vi);
        print(expect);
        print(retval);
        print();
    }
    releaseLinkedList(ret);
}

int main(int argc, char const *argv[]) {
    test_vi({1, 2, 3, 4, 5}, {5, 4, 3, 2, 1});
    test_vi({1, 2}, {2, 1});
    test_vi({}, {});

    return 0;
}
