#include "../inc.h"

// 这是先拿尾，再滑头双移
class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int csize = cardPoints.size(), vmax = 0, l = 0;
        for (int i = 0; i < k; ++i) vmax += cardPoints[csize - i - 1];
        int vcurr = vmax;
        if (k == csize) return vmax;
        for (int l = 1; l <= k; ++l) {
            vcurr -= cardPoints[csize - k + l - 1];
            vcurr += cardPoints[l - 1];
            vmax = max(vmax, vcurr);
        }

        return vmax;
    }
};

void test(vector<int>&& cardPoints, int k, int exepect) {
    save4print(cardPoints, k);
    auto ret = Solution().maxScore(cardPoints, k);
    assert_eq_ret(exepect, ret);
}

int main() {
    test({1, 2, 3, 4, 5, 6, 1}, 3, 12);
    test({2, 2, 2}, 2, 4);
    test({9, 7, 7, 9, 7, 7, 9}, 7, 55);
}
