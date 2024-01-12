#include "../inc.h"

class Solution {
   public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> n2count;
        int n = grid.size(), n2 = n * n, a, b;
        for (const auto& g : grid)
            for (int c : g) ++n2count[c];
        for (int i = 1; i <= n2; ++i) {
            if (n2count[i] == 0) a= i;
            else if (n2count[i] == 2) b = i;
        }
        return {b, a};
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
