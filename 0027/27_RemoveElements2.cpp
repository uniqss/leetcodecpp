#include "../inc.h"

/*
slow / fast 命名会更容易理解，更接近人的思维，比我写的 curr / valid 要好
*/

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast) {
            if (val != nums[fast]) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};

void test(vector<int>&& nums, int val, int expected) {
    save4print(nums, val);
    auto ret = Solution().removeElement(nums, val);
    assert_eq_ret(expected, ret);
}

int main() {
    test({3, 2, 2, 3}, 3, 2);
    test({0, 1, 2, 2, 3, 0, 4, 2}, 2, 5);

    return 0;
}
