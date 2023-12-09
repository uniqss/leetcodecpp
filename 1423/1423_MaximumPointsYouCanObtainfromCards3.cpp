#include "../inc.h"

// 官方题解也不错，思路很清晰
class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), windowsize = n - k;
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + windowsize, 0);
        int vmin = sum;
        for (int i = windowsize; i < n; ++i) {
            sum += cardPoints[i] - cardPoints[i - windowsize];
            vmin = min(vmin, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - vmin;
    }
};

void test(vector<int>&& cardPoints, int k, int exepect) {
    save4print(cardPoints, k);
    assert_eq_ret(exepect, Solution().maxScore(cardPoints, k));
}

int main() {
    test({1, 2, 3, 4, 5, 6, 1}, 3, 12);
    test({2, 2, 2}, 2, 4);
    test({9, 7, 7, 9, 7, 7, 9}, 7, 55);
}
