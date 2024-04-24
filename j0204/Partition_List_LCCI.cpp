#include "../inc.h"

class Solution {
   public:
    ListNode* partition(ListNode* head, int x) {}
};

void test(const vector<int>& vi, int x) {
    auto l = constructList(vi);
    auto ret = Solution().partition(l, x);
    ListAutoReleaser _(ret);
    auto retval = list2vals(ret);
    save4print(vi, x, retval);

    bool bok = true;
    do {
        if (retval.size() != vi.size()) {
            bok = false;
            break;
        }

        if (retval.empty()) break;

        bool less = retval[0] < x;
        for (size_t i = 1; i < retval.size() && bok; ++i) {
            if (retval[i] >= x) {
                if (less) {
                    less = false;
                }
            } else {
                if (!less) {
                    bok = false;
                }
            }
        }
    } while (false);

    assert_retnone(bok);
}

int main() {
    test({1, 4, 3, 2, 5, 2}, 3);
    return 0;
}
