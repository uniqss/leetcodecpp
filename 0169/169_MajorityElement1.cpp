#include "../inc.h"

/*
这样解也还行，空间o(n)时间o(n)
*/
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> dict;
        int ret = 0;
        int countmax = 0;
        for (int num : nums) {
            int count = dict[num] + 1;
            ++dict[num];
            if (countmax < count) {
                countmax = count;
                ret = num;
            }
        }
        return ret;
    }
};

void test(vector<int>&& nums, int expected) {
    Solution so;
    auto ret = so.majorityElement(nums);
    if (ret == expected) {
        print("ok.");
    } else {
        print("not ok.");
        print(nums);
        print(expected);
        print(ret);
    }
}

int main() {
    test({3, 2, 3}, 3);
    test({2, 2, 1, 1, 1, 2, 2}, 2);
    return 0;
}
