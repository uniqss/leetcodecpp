#include "../inc/inc.h"

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if (nums.size() < 4) return ret;
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        int64_t sumij = 0, sum = 0, target64 = target;
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                sumij = nums[i] + nums[j];
                l = j + 1;
                r = nums.size() - 1;
                while (l < r) {
                    sum = sumij + nums[l] + nums[r];
                    if (sum == target64) {
                        ret.push_back({nums[i], nums[j], nums[l], nums[r]});
                        ++l;
                        while (l < r && nums[l] == nums[l - 1]) ++l;
                        --r;
                        while (l < r && nums[r] == nums[r + 1]) --r;
                    } else if (sum > target64) {
                        --r;
                        while (l < r && nums[r] == nums[r + 1]) --r;
                    } else {
                        ++l;
                        while (l < r && nums[l] == nums[l - 1]) ++l;
                    }
                }
            }
        }

        return ret;
    }
};

void test(vector<int>&& nums, int target, vector<vector<int>>&& expect) {
    Solution so;
    auto ret = so.fourSum(nums, target);
    for_each(expect.begin(), expect.end(), [](vector<int>& arr) { sort(arr.begin(), arr.end()); });
    std::sort(expect.begin(), expect.end());

    for_each(ret.begin(), ret.end(), [](vector<int>& arr) { sort(arr.begin(), arr.end()); });
    sort(ret.begin(), ret.end());

    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(nums);
        print(target);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({1, 0, -1, 0, -2, 2}, 0, {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}});
    test({2, 2, 2, 2, 2}, 8, {{2, 2, 2, 2}});
    return 0;
}
