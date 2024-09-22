#include "../inc.h"

class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {}
};

void test(vector<int>&& arr, const vector<int>& expect) {
    save4print(arr);
    assert_eq_ret(expect, Solution().replaceElements(arr));
}

int main() {
    test({17, 18, 5, 4, 6, 1}, {18, 6, 6, 6, 1, -1});
    test({400}, {-1});
    return 0;
}
