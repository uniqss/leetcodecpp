#include "../inc.h"

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int round = digits.size() - 1;
        bool exceeding = false;
        while (round >= 0) {
            if (digits[round] < 9) {
                ++digits[round];
                return digits;
            } else {
                exceeding = true;
                digits[round] = 0;
            }
            --round;
        }
        if (exceeding) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

void test(vector<int>&& vi, const vector<int>& expect) {
    save4print(vi);
    assert_eq_ret(expect, Solution().plusOne(vi));
}

int main() {
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