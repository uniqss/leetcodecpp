#include "../inc.h"

class Solution {
   public:
    long long maxAlternatingSum(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        long long ret = 0;
        nums.insert(nums.begin(), 0);
        int edgeCount = 0, nsize = nums.size(), top = 0;
        for (int i = 1; i < nsize; ++i) {
            if (edgeCount % 2 == 0) {  // going up
                if (nums[i] >= nums[i - 1]) {
                    top = nums[i];
                    continue;
                } else {  // turn down
                    ++edgeCount;
                    top = nums[i - 1];
                }
            } else {
                if (nums[i] < nums[i - 1]) {
                    continue;
                } else {  // turn up
                    ++edgeCount;
                    ret += top - nums[i - 1];
                    top = nums[i];
                }
            }
        }

        ret += top;

        return ret;
    }
};

void test(vector<int>&& nums, long long expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.maxAlternatingSum(nums);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(nums_param);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({4, 2, 5, 3}, 7);
    test({5, 6, 7, 8}, 8);
    test({6, 2, 1, 2, 4, 5}, 10);
    return 0;
}
