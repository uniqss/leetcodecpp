#include "../inc/inc.h"

// 暴力
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        for (size_t l = 0; l < heights.size(); ++l) {
            for (size_t r = l; r < heights.size(); ++r) {
                int minh = INT_MAX;
                for (size_t i = l; i <= r; ++i) {
                    minh = min(minh, heights[i]);
                }
                ret = max(ret, int(r - l + 1) * minh);
            }
        }
        return ret;
    }
};

void test(vector<int>&& vi, int expect) {
    Solution s;
    int ret = s.largestRectangleArea(vi);
    if (ret != expect) {
        print("###### not ok");
    } else {
        print("ok");
    }
    print();
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