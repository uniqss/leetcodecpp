#include "../inc.h"

class Solution {
   public:
    bool uniqueOccurrences(vector<int>& arr) {}
};

void test(vector<int>&& arr, bool expect) {
    auto arr_param = arr;
    Solution so;
    auto ret = so.uniqueOccurrences(arr);
    assert_eq_ret(expect, ret);
    print(arr_param);
}

int main() {
    test({1, 2, 2, 1, 1, 3}, true);
    test({1, 2}, false);
    test({-3, 0, 1, -3, 1, 1, 1, -3, 10, 0}, true);
    return 0;
}
