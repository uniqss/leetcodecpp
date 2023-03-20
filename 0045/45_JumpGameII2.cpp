#include "../inc/inc.h"

// 中文官方题解1 据说cpp会超，太不科学了，java和go不会超
// 利用 0 <= nums[i] <= 1000 稍微优化一下

class Solution {
   public:
    int jump(vector<int>& nums) {
        int pos = nums.size() - 1;
        int steps = 0;
        while (pos > 0) {
            for (int i = max(0, pos - 1000); i < pos; ++i) {
                if (i + nums[i] >= pos) {
                    pos = i;
                    ++steps;
                    break;
                }
            }
        }
        return steps;
    }
};

void test(vector<int>&& nums, int expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.jump(nums);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(nums_param);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({2, 3, 1, 1, 4}, 2);
    test({2, 3, 0, 1, 4}, 2);
    return 0;
}
