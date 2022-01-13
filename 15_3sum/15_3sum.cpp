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
    pvraw(vi);
    ret = s.threeSum(vi);
    pvvraw(ret);

    vi = {3, 0, -2, -1, 1, 2};
    pvraw(vi);
    ret = s.threeSum(vi);
    pvvraw(ret);

    return 0;
}
