#include "../inc.h"

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {}
};

void test(vector<int>&& vi, const vector<int>& expect) {
    save4print(vi);
    assert_eq_ret(expect, Solution().plusOne(vi));
}

int main() {
    test({9, 9}, {1, 0, 0});
    test({1, 2, 3}, {1, 2, 4});
    test({4, 3, 2, 1}, {4, 3, 2, 2});
    test({0}, {1});
    test({9}, {1, 0});
}
/*
[1,2,3]
[4,3,2,1]
[0]
[9]
*/