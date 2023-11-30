#include "../inc.h"

class Solution {
   public:
    int sumSubarrayMins(vector<int>& arr) {}
};

void test(vector<int>&& arr, int expect) {
    save4print(arr);
    assert_eq_ret(expect, Solution().sumSubarrayMins(arr));
}

int main() {
    test({3, 1, 2, 4}, 17);
    test({11, 81, 94, 43, 3}, 444);
    return 0;
}
