#include "../inc.h"

class Solution {
   public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {}
};

void test(vector<int>&& spells, vector<int>&& potions, long long success, const vector<int>& expect) {
    save4print(spells, potions, success);
    assert_eq_ret(expect, Solution().successfulPairs(spells, potions, success));
}

int main() {
    test({5, 1, 3}, {1, 2, 3, 4, 5}, 7, {4, 0, 3});
    test({3, 1, 2}, {8, 5, 8}, 16, {2, 0, 2});
    return 0;
}
