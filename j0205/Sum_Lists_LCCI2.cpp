#include "../inc.h"

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /*
        7, 1, 6}, {5, 9, 2}, {2, 1, 9
        */
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        int remain = 0;
        ListNode ret;
        ListNode* tail = &ret;
        while (l1 != nullptr || l2 != nullptr || remain > 0) {
            if (l1 != nullptr) {
                remain += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                remain += l2->val;
                l2 = l2->next;
            }
            ListNode* curr = new ListNode(remain % 10);
            remain /= 10;
            tail->next = curr;
            tail = curr;
        }
        return ret.next;
    }
};

void test(const vector<int>& v1, const vector<int>& v2, const vector<int>& expect) {
    auto l1 = constructList(v1);
    auto l2 = constructList(v2);
    Solution so;
    auto ret = so.addTwoNumbers(l1, l2);
    auto retval = list2vals(ret);
    if (retval == expect) {
        print("ok");
    } else {
        print("not ok");
        print(v1);
        print(v2);
        print(expect);
        print(retval);
        print();
    }
    releaseLinkedList(l1);
    releaseLinkedList(l2);
    releaseLinkedList(ret);
}

int main() {
    // 看到这个测试用例，可以看出，即使用int64也放不下，我好像走错路了
    test({1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {5, 6, 4},
         {6, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1});
    test({0}, {0}, {0});
    test({5}, {5}, {0, 1});
    test({7, 1, 6}, {5, 9, 2}, {2, 1, 9});
    test({2, 4, 3}, {5, 6, 4}, {7, 0, 8});  // 342 + 465 = 807
    return 0;
}