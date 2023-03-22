#include "../inc.h"

/*
要小心的是这里没有fake头，所以一开始slow/fast的位置很玄妙，碰头以后，fast归到head位，其实是往后多走了一位，所以slow也要相应的多走一位。
一定要画图
*/
class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        /*
        1 2 3 4
        s f
          s   f
            *
        f     s

        1 2 3 4
        s f
          s   f
          f s
              *
        sf
        */
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                fast = head;
                slow = slow->next;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};

void test(const vector<int> &vi, int pos, int expect) {
    auto l = constructList(vi);
    ListAutoReleaser _(l);
    ListNode *curr = l, *tail = l;
    while (tail->next != nullptr) tail = tail->next;
    for (int i = 0; i < pos; ++i) {
        curr = curr->next;
    }
    tail->next = curr;

    Solution so;
    auto ret = so.detectCycle(l);
    int posret = 0;
    curr = l;
    while (curr != nullptr) {
        if (curr == ret) break;
        curr = curr->next;
        ++posret;
        if (posret > vi.size()) break;
    }
    if (posret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(vi);
        print(pos);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({3, 2, 0, -4}, 1, 1);
    return 0;
}
