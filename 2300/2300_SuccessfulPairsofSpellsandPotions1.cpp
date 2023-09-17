#include "../inc.h"

class Solution {
   public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int ssize = spells.size(), psize = potions.size();
        vector<int> ret;
        for (int spell : spells) {
            int l = 0, r = psize - 1;
            if (potions[l] * spell >= success) {
                ret.emplace_back(psize);
            } else if (potions[r] * spell < success) {
                ret.emplace_back(0);
            } else {
                while (l < r) {
                    int curr = l + (r - l) / 2;
                    if (potions[curr] * spell >= success) {
                        r = curr;
                    } else {
                        l = curr + 1;
                    }
                }
                ret.emplace_back(psize - r);
            }
        }
        return ret;
    }
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
