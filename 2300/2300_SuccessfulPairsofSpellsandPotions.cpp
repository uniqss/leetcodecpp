#include "../inc.h"

class Solution {
   public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {}
};

void test(vector<int>&& spells, vector<int>&& potions, long long success, const vector<int>& expect) {
    auto s_param = spells;
    auto p_param = potions;
    Solution so;
    auto ret = so.successfulPairs(spells, potions, success);
    assert_eq_ret(expect, ret);
    print(s_param);
    print(p_param);
    print(success);
}

int main() {
    test({5, 1, 3}, {1, 2, 3, 4, 5}, 7, {4, 0, 3});
    test({3, 1, 2}, {8, 5, 8}, 16, {2, 0, 2});
    return 0;
}
