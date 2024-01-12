#include "../inc.h"

class Solution {
   public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(), sum = 0, l = 0;
        unordered_set<int> exists;
        for (const auto& c : grid) {
            for (int r : c) {
                if (exists.count(r) > 0) l = r;
                exists.insert(r);
                sum += r;
            }
        }
        int n2 = n * n;
        return {l, n2 * (n2 + 1) / 2 - sum + l};
    }
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
