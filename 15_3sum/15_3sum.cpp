#include "../stl.h"

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    }
};

int main() {
    vector<int> vi;
    Solution s;
    vector<vector<int>> ret;

    vi = {-1, 0, 1, 2, -1, -4};
    pvi(vi);
    ret = s.threeSum(vi);
    pvvi(ret);

    vi = {3, 0, -2, -1, 1, 2};
    pvi(vi);
    ret = s.threeSum(vi);
    pvvi(ret);

    return 0;
}
