#include "../inc.h"

class Solution {
   public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ret;
        int n = variables.size();
        for (int i = 0; i < n; ++i) {
            const auto& v = variables[i];
            int a = v[0], b = v[1], c = v[2], m = v[3];
            int curr = 1;
            for (int i = 1; i <= b; ++i) {
                curr = (curr * a) % 10;
            }
            curr %= m;
            int ab10 = curr;
            curr = 1;
            for (int i = 1; i <= c; ++i) {
                curr = (curr * ab10) % m;
            }
            if (curr == target) ret.emplace_back(i);
        }
        return ret;
    }
};

void test(vector<vector<int>>&& v, int target, const vector<int>& expect) {
    save4print(v, target);
    assert_eq_ret(expect, Solution().getGoodIndices(v, target));
}

int main() {
    test({{9, 2, 8, 5}, {7, 8, 8, 8}, {8, 9, 6, 1}, {8, 6, 2, 2}, {3, 6, 3, 1}}, 9, {});
    test({{39, 3, 1000, 1000}}, 17, {});
    test({{2, 3, 3, 10}, {3, 3, 3, 1}, {6, 1, 1, 4}}, 2, {0, 2});
    test({{39, 3, 1000, 1000}}, 17, {});
    return 0;
}
