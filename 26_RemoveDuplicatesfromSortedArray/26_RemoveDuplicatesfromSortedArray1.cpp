#include "../stl.h"

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        int last = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != last) {
                nums[j] = nums[i];
                last = nums[i];
                ++j;
            }
        }
        return j;
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
