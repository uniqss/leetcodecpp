#include "../inc.h"

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
    }
};

void test(vector<int>&& vi) {
    pvraw(vi);
    Solution s;
    auto ret = s.plusOne(vi);
    pvraw(ret);
    pnewline();
}

int main() {
    test({1, 2, 3});
    test({4, 3, 2, 1});
    test({0});
    test({9});
}
/*
[1,2,3]
[4,3,2,1]
[0]
[9]
*/