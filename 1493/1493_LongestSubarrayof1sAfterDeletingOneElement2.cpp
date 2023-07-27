#include "../inc.h"

class Solution {
   public:
    int longestSubarray(vector<int>& nums) {
        int nsize = nums.size();
        vector<int> pre(nsize), suf(nsize);
        int ret = 0;
        pre[0] = nums[0];
        for (int i = 1; i < nsize; i++) {
            pre[i] = nums[i] ? pre[i - 1] + 1 : 0;
        }
        suf[nsize - 1] = nums[nsize - 1];
        for (int i = nsize - 2; i >= 0; i--) {
            suf[i] = nums[i] ? suf[i + 1] + 1 : 0;
        }
        for (int i = 0; i < nsize; i++) {
            int l = i == 0 ? 0 : pre[i - 1];
            int r = i == nsize - 1 ? 0 : suf[i + 1];
            ret = max(ret, l + r);
        }

        return ret;
    }
};

void test(vector<int>&& nums, int expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.longestSubarray(nums);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(nums_param);
        print(expect);
        print(ret);
    }
}

int main() {
    test({1, 1, 0, 0, 1, 1, 1, 0, 1}, 4);
    test({1, 1, 0, 1}, 3);
    test({0, 1, 1, 1, 0, 1, 1, 0, 1}, 5);
    test({1, 1, 1}, 2);
    return 0;
}
