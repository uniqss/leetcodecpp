#include "../inc.h"

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] != 9) {
                ++digits[i];
                for (int j = n - 1; j > i; --j) digits[j] = 0;
                return digits;
            }
        }
        digits.resize(n + 1, 0);
        for (int i = 1; i < n; ++i) digits[i] = 0;
        digits[0] = 1;
        return digits;
    }
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