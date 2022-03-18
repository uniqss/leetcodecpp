#include "../inc.h"

/*
官方题解，细节还是挺多的
[i + 1, n]在交换后是有序的 这个很有意思，可以用反证法证明，或者正向推理一下也可以证明
注意相等的情况下的处理
这种写法代码少了很多的edge condition，多了一次swap
对比而言确实比自己摸索出来的写法要精炼的多

*/

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                --j;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

void test(vector<int>&& nums, vector<int>&& expect) {
    Solution so;
    vector<int> nums_saved = nums;

    so.nextPermutation(nums);
    if (nums == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        pvraw(nums_saved);
        pvraw(expect);
        pvraw(nums);
    }
}

int main() {
    test({1, 1}, {1, 1});
    test({1, 5, 1}, {5, 1, 1});
    test({3, 2, 1}, {1, 2, 3});
    test({3, 1, 2}, {3, 2, 1});
    test({2, 3, 1}, {3, 1, 2});
    test({1, 2, 3}, {1, 3, 2});
    test({1, 1, 5}, {1, 5, 1});
    return 0;
}
