#include "../inc/inc.h"

class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {}
};

void test(vector<int>&& nums, vector<vector<int>>&& expect) {
    Solution so;
    auto ret = so.subsets(nums);
    std::sort(ret.begin(), ret.end());
    std::sort(expect.begin(), expect.end());
    if (expect == ret) {
        print("ok.");
    } else {
        print("not ok.");
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({1, 2, 3}, {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}});
    test({0}, {{}, {0}});
}
