#include "../inc.h"

class Solution {
   public:
    int largestAltitude(vector<int>& gain) {}
};

void test(vector<int>&& gain, int expect) {
    save4print(gain);
    assert_eq_ret(expect, Solution().largestAltitude(gain));
}

int main() {
    test({-5, 1, 5, 0, -7}, 1);
    test({-4, -3, -2, -1, 4, 3, 2}, 0);
    return 0;
}
