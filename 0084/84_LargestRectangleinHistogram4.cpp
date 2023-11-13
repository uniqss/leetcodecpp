#include "../inc.h"

/*
这个解法吧，说毛病也没啥毛病，就是吃内存猛了点，写的还是比较清晰的
*/
class Solution {
    struct Element {
        int height;
        int leftidx;
        int idx;
    };

   public:
    int largestRectangleArea(vector<int>& heights) {
        heights.emplace_back(0);
        int ret = 0, curr = 0, hsize = heights.size();
        stack<Element> stk;
        for (int i = 0; i < hsize; ++i) {
            int h = heights[i];
            while (!stk.empty() && h < stk.top().height) {
                curr = stk.top().height * (i - stk.top().leftidx);
                ret = max(ret, curr);
                stk.pop();
            }
            int leftidx = 0;
            if (!stk.empty()) leftidx = stk.top().idx + 1;
            stk.push({h, leftidx, i});
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
