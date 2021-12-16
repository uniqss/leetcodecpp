#include "../stl.h"

/*
在后面加个0，每次只结算当前遇到元素的前面，不包括当前元素
在栈上首先扔个-1/0
30 20 40 0
[-1/0]
30
    遇大压栈
[-1/0, 0/30]
20
    val (0 - -1) * 30 = 30
    遇小结算
[-1/0, 1/20]
40
    遇大压栈
[-1/0, 1/20, 2/40]
0
    val (2 - 1) * 40 = 40
    val (2 - -1) * 20 = 60
    遇小结算 结算面积=(当前idx - 结算左栈元素idx) * 结算高度
因为是vector o(1) 我们只存下标，不存值
遇等如何处理？把上一个元素出栈新元素入栈，或者直接修改栈顶，这样可让后续少结算一次
这样下标-1很麻烦，在数组前面也加个0，这样就不用压前面的-1了，一直有个0在栈里。后面有相等规则如果有元素等于0的话，也是合理，后续只用结算到新0位置而不用结算到起始0位置
*/
// 使用栈
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        heights.insert(heights.begin(), 0);
        stack<int> si;
        si.push(0);
        int ret = 0;
        for (size_t idx = 0; idx < heights.size(); ++idx) {
            if (heights[idx] > heights[si.top()]) {
                si.push(idx);
            } else if (heights[idx] == heights[si.top()]) {
                si.top() = idx;
            } else {
                while (heights[idx] < heights[si.top()]) {
                    int maxheightidx = si.top();
                    si.pop();
                    int area = (idx - si.top() - 1) * heights[maxheightidx];
                    ret = max(ret, area);
                }
                si.push(idx);
            }
        }

        return ret;
    }
};

void test(vector<int>&& vi, int expect) {
    Solution s;
    int ret = s.largestRectangleArea(vi);
    if (ret != expect) {
        ps("###### not ok");
        pi(expect);
        pi(ret);
    } else {
        ps("ok");
    }
    pnewline();
}

int main() {
    test({2, 1, 5, 6, 2, 3}, 10);
    test({2, 4}, 4);
    test({2, 1, 2}, 3);
    return 0;
}

/*
[2,1,5,6,2,3]
[2,4]
*/