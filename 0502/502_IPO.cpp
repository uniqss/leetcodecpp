#include "../inc.h"

class Solution {
   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {}
};

void test(int k, int w, vector<int>&& profits, vector<int>&& capital, int expect) {
    save4print(k, w, profits, capital);
    assert_eq_ret(expect, Solution().findMaximizedCapital(k, w, profits, capital));
}

int main() {
    test(11, 11, {3, 2, 1}, {13, 12, 11}, 17);
    test(11, 11, {1, 2, 3}, {11, 12, 13}, 17);
    test(1, 2, {1, 2, 3}, {1, 1, 2}, 5);
    test(2, 0, {1, 2, 3}, {0, 1, 1}, 4);
    test(3, 0, {1, 2, 3}, {0, 1, 2}, 6);
    return 0;
}
