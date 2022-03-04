#include "inc.h"

/*
三种情况：
非空前置不移 nums[i] != 0 && i == j  ++j
非空移动  nums[i] != 0 && i != j   nums[j] = nums[i], nums[i] = 0, ++j
空不移 nothing

*/
class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (i != j) {
                    nums[j] = nums[i];
                    nums[i] = 0;
                }
                ++j;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> vi;
    vi = {1, 0, 2, 3, 0, 4};
    s.moveZeroes(vi);
    pvraw(vi);

    vi = {0, 1, 0, 0, 5, 0};
    s.moveZeroes(vi);
    pvraw(vi);
    return 0;
}
