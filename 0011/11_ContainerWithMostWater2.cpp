#include "../inc.h"

/*
two pointer
*/
class Solution {
   public:
    int maxArea(vector<int> &height) {
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

void test(vector<int> &&height, int expect) {
    save4print(height);
    assert_eq_ret(expect, Solution().maxArea(height));
}

int main(int argc, char const *argv[]) {
    test({1, 8, 6, 2, 5, 4, 8, 3, 7}, 49);
    test({1, 1}, 1);
    test({4, 3, 2, 1, 4}, 16);
    test({1, 2, 1}, 2);

    return 0;
}
