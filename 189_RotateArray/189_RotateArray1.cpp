#include "../inc.h"

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        int ntmp = 0;
        while (k-- > 0) {
            ntmp = nums[nums.size() - 1];
            std::copy(nums.begin(), nums.end() - 1, nums.begin() + 1);
            nums[0] = ntmp;
        }
    }
};

int main() {
    Solution s;
    vector<int> vi;

    vi = {1, 2, 3, 4, 5, 6, 7};
    s.rotate(vi, 3);
    pvraw(vi);

    vi = {-1, -100, 3, 99};
    s.rotate(vi, 2);
    pvraw(vi);

    return 0;
}
