#include "../inc.h"

class Solution {
   public:
    int candy(vector<int>& ratings) {}
};

void test(vector<int>&& ratings, int expect) {
    save4print(ratings);
    Solution so;
    auto ret = so.candy(ratings);
    assert_eq_ret(expect, ret);
}

int main() {
    test({1, 3, 2, 2, 1}, 7);
    test({1, 3, 4, 5, 2}, 11);
    test({1, 0, 2}, 5);
    test({1, 2, 2}, 4);
    return 0;
}
