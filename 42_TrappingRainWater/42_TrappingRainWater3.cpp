#include "../inc.h"

// 非常暴力非常粗糙的解法
class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) {
            return 0;
        }

        // 问题三分，增长段、平滑段、减少段
        int maxIdxL = 0;
        int maxIdxR = 0;
        int max = 0;
        for (int i = 0; i < height.size(); i++) {
            max = std::max(max, height[i]);
        }
        bool first = true;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] >= max) {
                if (first) {
                    first = false;
                    maxIdxL = i;
                }
                maxIdxR = i;
            }
        }
        int ret = 0;
        // 增区间
        int currMax = 0;
        for (int i = 0; i < maxIdxL; i++) {
            if (height[i] < currMax) {
                ret += currMax - height[i];
            }
            if (height[i] > currMax) {
                currMax = height[i];
            }
        }
        // 平区间
        for (int i = maxIdxL + 1; i < maxIdxR; i++) {
            if (height[i] < max) {
                ret += max - height[i];
            }
        }
        // 减区间
        currMax = 0;
        for (int i = height.size() - 1; i > maxIdxR; i--) {
            if (height[i] < currMax) {
                ret += currMax - height[i];
            }
            if (height[i] > currMax) {
                currMax = height[i];
            }
        }
        return ret;
    }
};

void test(vector<int>&& vi, int expect) {
    Solution s;
    int ret = s.trap(vi);
    if (ret == expect) {
        praw("ok");
    } else {
        praw("### not ok ");
        pvraw(vi);
        praw(expect);
        praw(ret);
        pnewline();
    }
}

int main() {
    test({2, 1, 3, 1}, 1);
    test({2, 1, 0, 1, 3, 1}, 4);
    test({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6);
    test({4, 2, 0, 3, 2, 5}, 9);
    return 0;
}
