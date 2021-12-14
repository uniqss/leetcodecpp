#include "../stl.h"

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int uniqueCount = 0;
        int last = INT_MIN;
        for (int idx = 0; idx < nums.size(); ++idx) {
            if (nums[idx] == last) {
            } else {
                nums[uniqueCount] = nums[idx];
                last = nums[idx];
                ++uniqueCount;
            }
        }
        return uniqueCount;
    }
};

int main() {
    Solution s;
    vector<int> vi;
    int ret = 0;

    vi = {1, 1, 2};
    ret = s.removeDuplicates(vi);
    pvi(vi);
    pi(ret);

    vi = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    ret = s.removeDuplicates(vi);
    pvi(vi);
    pi(ret);

    return 0;
}
