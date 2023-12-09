#include "../inc.h"

class Solution {
   public:
    vector<int> findPeaks(vector<int>& mountain) {}
};

void test(vector<int>&& moutain, vector<int> expect) {
    save4print(moutain);
    assert_eq_ret(expect, Solution().findPeaks(moutain));
}

int main() {
    test({2, 4, 4}, {});
    test({1, 4, 3, 8, 5}, {1, 3});
    return 0;
}
