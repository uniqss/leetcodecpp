#include "../inc/inc.h"

// 貌似稍微苗条一丢丢
class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if (nums.size() < 4) return ret;
        sort(nums.begin(), nums.end());
        for (int first = 0; first < nums.size() - 3; ++first) {
            if (first > 0 && nums[first] == nums[first - 1]) continue;
            for (int second = first + 1; second < nums.size() - 2; ++second) {
                if (second > first + 1 && nums[second] == nums[second - 1]) continue;
                int64_t sum12 = nums[first] + nums[second];
                int third = second + 1, fourth = nums.size() - 1;
                while (third < fourth) {
                    int64_t sum = sum12 + nums[third] + nums[fourth];
                    if (sum > target)
                        --fourth;
                    else if (sum < target)
                        ++third;
                    else {
                        ret.push_back({nums[first], nums[second], nums[third], nums[fourth]});
                        ++third;
                        while (third < fourth && nums[third] == nums[third - 1]) ++third;
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
