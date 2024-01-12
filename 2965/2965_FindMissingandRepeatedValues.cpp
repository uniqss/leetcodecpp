#include "../inc.h"

class Solution {
   public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {}
};

void test(vector<vector<int>>&& g, const vector<int>& expect) {
    save4print(g);
    assert_eq_ret(expect, Solution().findMissingAndRepeatedValues(g));
}

int main() {
    test({{1, 3}, {2, 2}}, {2, 4});
    test({{9, 1, 7}, {8, 9, 2}, {3, 4, 6}}, {9, 5});
    return 0;
}
