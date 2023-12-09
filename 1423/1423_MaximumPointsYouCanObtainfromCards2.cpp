#include "../inc.h"

class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int csize = cardPoints.size(), vmax = 0;
        for (int i = 0; i < k; ++i) vmax += cardPoints[i];
        int vcurr = vmax;
        for (int i = 0; i < k; ++i) {
            vcurr -= cardPoints[k - i - 1];
            vcurr += cardPoints[csize - i - 1];
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
