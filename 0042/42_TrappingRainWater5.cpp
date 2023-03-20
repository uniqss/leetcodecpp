#include "../inc.h"

// stk 解法
class Solution {
   public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int ret = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!stk.empty() && height[stk.top()] < height[i]) {
                int idxlow = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    ret += (min(height[stk.top()], height[i]) - height[idxlow]) * (i - stk.top() - 1);
                }
            }
            stk.push(i);
        }
        return ret;
    }
};

void test(vector<int>&& vi, int expect) {
    Solution s;
    int ret = s.trap(vi);
    if (ret == expect) {
        print("ok");
    } else {
        print("### not ok ");
        print(vi);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({2, 1, 3, 1}, 1);
    test({2, 1, 0, 1, 3, 1}, 4);
    test({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6);
    test({4, 2, 0, 3, 2, 5}, 9);
    return 0;
}
