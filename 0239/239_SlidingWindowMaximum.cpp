#include "../inc.h"

class Solution {
   public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {}
};

void test(const vector<int>& nums, int k, const vector<int>& expect) {
    Solution s;
    auto ret = s.maxSlidingWindow(nums, k);
    if (ret == expect) {
        print("ok");
    } else {
        print("##### not ok");
        print(nums);
        print(k);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({1, 3, 1, 2, 0, 5}, 3, {3, 3, 2, 5});
    test({7, 2, 4}, 2, {7, 4});
    test({1, 3, -1, -3, 5, 3, 6, 7}, 3, {3, 3, 5, 5, 6, 7});
    test({1}, 1, {1});
    return 0;
}
