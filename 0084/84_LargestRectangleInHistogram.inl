#include "../inc.h"

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        stack<int> stackIdx;
        heights.push_back(0);
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!stackIdx.empty() && heights[i] < heights[stackIdx.top()]) {
                int idx = stackIdx.top();
                stackIdx.pop();
                int width = i;
                if (!stackIdx.empty()) {
                    width = i - stackIdx.top() - 1;
                }
                int height = heights[idx];
                int area = width * height;
                maxArea = std::max(area, maxArea);
            }
            stackIdx.push(i);
        }

        return maxArea;
    }
};

void test(vector<int>&& vi, int expect) {
    save4print(vi);
    assert_eq_ret(expect, Solution().largestRectangleArea(vi));
}

int main() {
    test({2, 0, 2}, 2);
    test({2, 1, 5, 6, 2, 3}, 10);
    test({2, 4}, 4);
    test({2, 1, 2}, 3);
    test({5}, 5);
    return 0;
}
