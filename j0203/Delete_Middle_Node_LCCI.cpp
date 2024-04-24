#include "../inc.h"

// 这个题目是shit，可以不用做，直接next
class Solution {
   public:
    void deleteNode(ListNode* node) {}
};

void test(const vector<int>& vi, const vector<int>& expect) {
    save4print(vi);
    auto l = constructList(vi);
    ListAutoReleaser _(l);
    if (vi.size() >= 2) {
        Solution().deleteNode(l->next);
    }
    auto ret = list2vals(l);
    assert_eq_ret(expect, ret);
}

int main() {
    test({4, 5, 1, 9}, {4, 1, 9});
    test({5}, {5});
    test({5, 6}, {5, 6});
    return 0;
}
