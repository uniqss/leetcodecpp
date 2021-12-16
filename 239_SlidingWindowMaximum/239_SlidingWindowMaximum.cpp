#include "../stl.h"

// force
class Solution {
   public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    }
};

void test(const vector<int>& nums, int k, const vector<int>& expect) {
    pvi(nums);
    pi(k);
    Solution s;
    auto ret = s.maxSlidingWindow(nums, k);
    if (ret == expect) {
        ps("ok");
    } else {
        ps("##### not ok");
        pvi(expect);
        pvi(ret);
    }
    pnewline();
}

int main() {
    test({7, 2, 4}, 2, {7, 4});
    test({1, 3, -1, -3, 5, 3, 6, 7}, 3, {3, 3, 5, 5, 6, 7});
    test({1}, 1, {1});
    return 0;
}
