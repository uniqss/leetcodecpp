#include "../stl.h"

class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.size() < 2) return 0;
        vector<int> dpl(height.size(), height[0]);
        vector<int> dpr(height.size(), height[height.size() - 1]);
        for (size_t i = 1; i < height.size(); ++i) {
            dpl[i] = max(height[i], dpl[i - 1]);
            int ir = height.size() - 1 - i;
            dpr[ir] = max(height[ir], dpr[ir + 1]);
        }

        int ret = 0;
        for (size_t i = 0; i < height.size(); ++i) {
            ret += min(dpl[i], dpr[i]) - height[i];
        }
        return ret;
    }
};

void test(vector<int>&& vi, int expect) {
    pvi(vi);
    Solution s;
    int ret = s.trap(vi);
    if (ret == expect) {
        ps("ok");
    } else {
        ps("### not ok ");
        pi(expect);
        pi(ret);
    }
}

int main() {
    test({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6);
    test({4, 2, 0, 3, 2, 5}, 9);
    return 0;
}

/*
[0,1,0,2,1,0,1,3,2,1,2,1]
[4,2,0,3,2,5]
*/