#include "../inc.h"

/*
对2的优化
*/
// 使用栈
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> si;
        int ret = 0;
        for (size_t idx = 0; idx < heights.size(); ++idx) {
            while (!si.empty() && heights[idx] < heights[si.top()]) {
                int maxidx = si.top();
                si.pop();
                int width = idx;  // idx - (-1) - 1. if stack is empty, [0, idx).
                if (!si.empty()) width = idx - si.top() - 1;
                ret = max(ret, width * heights[maxidx]);
            }
            si.push(idx);
        }

        return ret;
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
