#include "../inc.h"

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {}
};

void test(vector<vector<int>>&& listvals, const vector<int>& expect) {
    save4print(listvals);
    vector<ListNode*> lists;
    ListAutoReleaser _;
    for (int i = 0; i < listvals.size(); ++i) {
        lists.emplace_back(constructList(listvals[i]));
    }
    _.Append(lists);
    auto ret = Solution().mergeKLists(lists);
    _.Append(ret);
    assert_eq_ret(expect, list2vals(ret));
}

int main() {
    test({{1, 4, 5}, {1, 3, 4}, {2, 6}}, {1, 1, 2, 3, 4, 4, 5, 6});
    test({}, {});
    test({{}}, {});
    return 0;
}
