#include "../inc.h"

// cleaner

class Solution {
   public:
    int maxArea(vector<int> &height) {
        int l = 0, r = height.size() - 1;
        int ret = 0;
        int area = 0;
        while (l < r) {
            area = (r - l) * min(height[l], height[r]);
            ret = max(ret, area);
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        return ret;
    }
};

void test(vector<int> &&height, int expect) {
    save4print(height);
    assert_eq_ret(expect, Solution().maxArea(height));
}

int main(int argc, char const *argv[]) {
    test({1, 8, 6, 2, 5, 4, 8, 3, 7}, 49);
    test({1, 1}, 1);
    test({4, 3, 2, 1, 4}, 16);
    test({1, 2, 1}, 2);

    return 0;
}
