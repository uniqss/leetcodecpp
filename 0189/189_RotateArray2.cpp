#include "../inc.h"

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        int ntmp = 0;
        k = k % nums.size();
        while (k-- > 0) {
            ntmp = nums[nums.size() - 1];
            std::copy(nums.begin(), nums.end() - 1, nums.begin() + 1);
            nums[0] = ntmp;
        }
    }
};

void test(vector<int>&& nums, int k, const vector<int>& expect) {
    vector<int> pnums = nums;
    Solution so;
    so.rotate(nums, k);
    if (nums == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(pnums);
        print(k);
        print(expect);
        print(nums);
        print();
    }
}

int main() {
    test({1, 2, 3, 4, 5, 6, 7}, 3, {5, 6, 7, 1, 2, 3, 4});
    test({-1, -100, 3, 99}, 2, {3, 99, -1, -100});

    return 0;
}
