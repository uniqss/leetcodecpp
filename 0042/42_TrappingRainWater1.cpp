#include "../inc/inc.h"

// dp
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
