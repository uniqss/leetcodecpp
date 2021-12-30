#include "../stl.h"

// two pointer
class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.size() < 2) return 0;
        int l = 1;
        int r = height.size() - 2;
        int lmax = height[0];
        int rmax = height[r + 1];
        int ret = 0;
        while (l <= r) {
            if (lmax < rmax) {
                if (height[l] < lmax) {
                    ret += lmax - height[l];
                } else {
                    lmax = height[l];
                }
                ++l;
            } else {
                if (height[r] < rmax) {
                    ret += rmax - height[r];
                } else {
                    rmax = height[r];
                }
                --r;
            }
        }
        return ret;
    }
};

void test(vector<int>&& vi, int expect) {
    pvi(vi);
    Solution s;
    int ret = s.trap(vi);
    if (ret == expect) {
        praw("ok");
    } else {
        praw("### not ok ");
        praw(expect);
        praw(ret);
    }
}

int main() {
    test({2, 1, 3, 1}, 1);
    test({2, 1, 0, 1, 3, 1}, 4);
    test({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6);
    test({4, 2, 0, 3, 2, 5}, 9);
    return 0;
}

/*
[0,1,0,2,1,0,1,3,2,1,2,1]
[4,2,0,3,2,5]
*/