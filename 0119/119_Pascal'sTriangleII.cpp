#include "../inc.h"

class Solution {
   public:
    vector<int> getRow(int rowIndex) {}
};

void test(int rowIndex, const vector<int>& expect) {
    save4print(rowIndex);
    assert_eq_ret(expect, Solution().getRow(rowIndex));
}

int main() {
    test(3, {1, 3, 3, 1});
    test(0, {1});
    test(1, {1, 1});
    return 0;
}
