#include "../inc/inc.h"

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int valid = 0, size = nums.size();
        for (int curr = 0; curr < size; ++curr) {
            if (val != nums[curr]) {
                nums[valid++] = nums[curr];
            }
        }
        return valid;
    }
};

void test(vector<int>&& nums, int val, int expected) {
    Solution so;
    auto ret = so.removeElement(nums, val);
    if (ret == expected) {
        print("ok");
    } else {
        print("not ok.");
        print(nums);
        print(val);
        print(expected);
        print();
    }
}

int main() {
    test({3, 2, 2, 3}, 3, 2);
    test({0, 1, 2, 2, 3, 0, 4, 2}, 2, 5);

    return 0;
}
