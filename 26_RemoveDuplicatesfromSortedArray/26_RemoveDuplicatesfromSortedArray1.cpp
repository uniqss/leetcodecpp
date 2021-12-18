#include "../stl.h"

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int last = INT_MIN;
        int valid = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != last) {
                nums[valid++] = nums[i];
                last = nums[i];
            }
        }
        return valid;
    }
};

int main() {
    Solution s;
    vector<int> vi;
    int ret = 0;

    vi = {1, 1, 2};
    ret = s.removeDuplicates(vi);
    pvi(vi);
    praw(ret);

    vi = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    ret = s.removeDuplicates(vi);
    pvi(vi);
    praw(ret);

    return 0;
}
