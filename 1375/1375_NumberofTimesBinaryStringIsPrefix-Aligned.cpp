#include "../inc.h"

class Solution {
   public:
    int numTimesAllBlue(vector<int>& flips) {}
};

void test(vector<int>&& flips, int expect) {
    auto flips_param = flips;
    Solution so;
    auto ret = so.numTimesAllBlue(flips);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(flips_param);
        print(expect);
        print(ret);
    }
}

int main() {
    test({3, 2, 4, 1, 5}, 2);
    test({4, 1, 2, 3}, 1);
    return 0;
}
