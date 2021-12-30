#include "../stl.h"

// brute-force
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (target == nums[i] + nums[j]) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};

int main() {
    Solution s;
    vector<int> vi;
    int target = 0;
    vector<int> result;

    vi = {2, 7, 11, 15};
    target = 9;
    result = s.twoSum(vi, target);
    pvi(result);

    vi = {3, 2, 4};
    target = 6;
    result = s.twoSum(vi, target);
    pvi(result);

    vi = {3, 3};
    target = 6;
    result = s.twoSum(vi, target);
    pvi(result);

    return 0;
}
