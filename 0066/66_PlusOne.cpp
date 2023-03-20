#include "../inc/inc.h"

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {}
};

void test(vector<int>&& vi, const vector<int>& expect) {
    Solution s;
    auto ret = s.plusOne(vi);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(vi);
        print(expect);
        print(ret);
        print();
    }
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