#include "stl.h"

/*
two pointer
*/
class Solution {
   public:
    int maxArea(vector<int> &height) {
        int curr = 0;
        int l = 0;
        int r = height.size() - 1;
        int lmax = height[l];
        int rmax = height[r];
        int ret = min(height[l], height[r]) * (r - l);
        while (l < r) {
            if (height[l] < height[r]) {
                ++l;
                if (l < r && height[l] > lmax) {
                    lmax = height[l];
                    ret = max(min(height[l], height[r]) * (r - l), ret);
                }
            } else {
                --r;
                if (l < r && height[r] > rmax) {
                    rmax = height[r];
                    ret = max(min(height[l], height[r]) * (r - l), ret);
                }
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> vi = {1, 1};
    int ret = s.maxArea(vi);
    cout << ret << endl;
    return 0;
}
