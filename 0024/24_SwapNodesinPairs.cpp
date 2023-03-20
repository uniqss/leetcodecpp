#include "../inc/inc.h"

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {}
};

void test(const std::vector<int>& vi, const vector<int>& expect) {
    ListNode* head = nullptr;
    Solution s;
    ListNode* ret = nullptr;

    head = constructList(vi);
    ret = s.swapPairs(head);
    auto retvals = list2vals(ret);
    if (retvals == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(vi);
        print(expect);
        print(retvals);
    }
    releaseLinkedList(ret);
}

int main(int argc, char const* argv[]) {
    test({}, {});
    test({1}, {1});
    test({1, 2}, {2, 1});
    test({1, 2, 3}, {2, 1, 3});
    test({1, 2, 3, 4}, {2, 1, 4, 3});
    test({1, 2, 3, 4, 5}, {2, 1, 4, 3, 5});

    return 0;
}
