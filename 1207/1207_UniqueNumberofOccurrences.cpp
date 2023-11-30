#include "../inc.h"

class Solution {
   public:
    bool uniqueOccurrences(vector<int>& arr) {}
};

void test(vector<int>&& arr, bool expect) {
    save4print(arr);
    assert_eq_ret(expect, Solution().uniqueOccurrences(arr));
}

int main() {
    test({1, 2, 2, 1, 1, 3}, true);
    test({1, 2}, false);
    test({-3, 0, 1, -3, 1, 1, 1, -3, 10, 0}, true);
    return 0;
}
