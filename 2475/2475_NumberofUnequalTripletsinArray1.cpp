#include "../inc.h"

class Solution {
   public:
    int unequalTriplets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ucount;
        int last = nums[0], count = 1;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == last)
                ++count;
            else {
                ucount.emplace_back(count);
                last = nums[i];
                count = 1;
            }
        }
        ucount.emplace_back(count);
        if (ucount.size() < 3) return 0;
        int ret = 0;
        for (int i = 0; i < ucount.size() - 2; i++) {
            for (int j = i + 1; j < ucount.size() - 1; j++) {
                for (int k = j + 1; k < ucount.size(); k++) {
                    ret += ucount[i] * ucount[j] * ucount[k];
                }
            }
        }

        return ret;
    }
};

void test(vector<int>&& nums, int expect) {
    Solution so;
    auto ret = so.unequalTriplets(nums);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(nums);
        print(expect);
        print(ret);
    }
}

int main() {
    test({4, 4, 2, 4, 3}, 3);
    test({1, 1, 1, 1, 1}, 0);
    return 0;
}
