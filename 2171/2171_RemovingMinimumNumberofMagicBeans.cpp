#include "../inc.h"


using LL = long long;

class Solution {
   public:
    long long minimumRemoval(vector<int>& beans) {}
};

void test(vector<int>&& beans, LL expect) {
    save4print(beans);
    assert_eq_ret(expect, Solution().minimumRemoval(beans));
}

int main() {
    test({4, 1, 6, 5}, 4);
    test({2, 10, 3, 2}, 7);
    return 0;
}