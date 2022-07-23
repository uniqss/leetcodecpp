#include "../inc.h"

/*
force
*/
class Solution {
   public:
    int maxArea(vector<int> &height) {
        int ret = 0;
        int curr = 0;
        for (int l = 0; l < height.size() - 1; ++l) {
            for (int r = l + 1; r < height.size(); ++r) {
                curr = std::min(height[l], height[r]) * (r - l);
                if (curr > ret) ret = curr;
            }
        }
        return ret;
    }
};

void test(vector<int> &&height, int expect) {
    const vector<int> param_height = height;
    Solution so;
    auto ret = so.maxArea(height);
    if (ret == expect) {
        praw("ok");
    } else {
        praw("not ok.");
        pvraw(param_height);
        praw(expect);
        praw(ret);
        pnewline();
    }
}

int main(int argc, char const *argv[]) {
    test({1, 8, 6, 2, 5, 4, 8, 3, 7}, 49);
    test({1, 1}, 1);
    test({4, 3, 2, 1, 4}, 16);
    test({1, 2, 1}, 2);

    return 0;
}
