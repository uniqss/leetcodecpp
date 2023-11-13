#include "../inc.h"

/*
代码写的像猪拱的
*/
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> longestbegin, longestend;
        int ret = 0, curr = 0;
        unordered_set<int> exist;
        for (int n : nums) {
            if (exist.count(n) > 0) continue;
            exist.insert(n);
            int c1 = longestbegin.count(n + 1), c2 = longestend.count(n - 1);
            if (c1 > 0 && c2 > 0) {
                curr = longestbegin[n + 1] + longestend[n - 1] + 1;
                longestbegin[n - longestend[n - 1]] = curr;
                longestend[n + longestbegin[n + 1]] = curr;
            } else if (c1 > 0) {
                curr = longestbegin[n + 1] + 1;
                longestbegin[n] = curr;
                longestend[n + curr - 1] = curr;
            } else if (c2 > 0) {
                curr = longestend[n - 1] + 1;
                longestend[n] = curr;
                longestbegin[n - curr + 1] = curr;
            } else {
                curr = 1;
                longestend[n] = curr;
                longestbegin[n] = curr;
            }
            ret = max(ret, curr);
        }
        return ret;
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    Solution so;
    auto ret = so.longestConsecutive(nums);
    assert_eq_ret(expect, ret);
}

int main() {
    test({-6, 8, -5, 7, -9, -1, -7, -6, -9, -7, 5, 7, -1, -8, -8, -2, 0}, 5);
    test({100, 4, 200, 1, 3, 2}, 4);
    test({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9);
    return 0;
}
