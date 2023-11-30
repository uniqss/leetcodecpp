#include "../inc.h"

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), carry = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] == 9)
                digits[i] = 0, carry = 1;
            else {
                ++digits[i], carry = 0;
                break;
            }
        }
        if (carry > 0) digits.insert(digits.begin(), 1);

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