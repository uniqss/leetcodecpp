#include "../inc.h"

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {}
};

void test(vector<int>&& nums, int k, vector<int>&& expect) {
    Solution so;
    auto ret = so.topKFrequent(nums, k);
    sort(expect.begin(), expect.end());
    sort(ret.begin(), ret.end());
    if (expect == ret) {
        praw("ok");
    } else {
        praw("not ok");
        pvraw(nums);
        praw(k);
        pvraw(expect);
        pvraw(ret);
        pnewline();
    }
}

int main() {
    test({1, 1, 1, 2, 2, 3}, 2, {1, 2});
    test({1}, 1, {1});
    return 0;
}
