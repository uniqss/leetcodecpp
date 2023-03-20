#include "../inc/inc.h"

// force
class Solution {
   public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
        if (k <= 1) return nums;
        vector<int> vi(k, INT_MIN);

        vector<int> ret;
        int maxcache = INT_MIN;
        for (int i = 0; i < (int)nums.size(); ++i) {
            int viold = vi[i % k];
            vi[i % k] = nums[i];
            if (i >= k - 1) {
                if (maxcache == INT_MIN || (nums[i] < maxcache && viold == maxcache)) {
                    maxcache = INT_MIN;
                    for (size_t j = 0; j < vi.size(); ++j) {
                        maxcache = max(maxcache, vi[j]);
                    }
                } else if (nums[i] > maxcache) {
                    maxcache = nums[i];
                }
                ret.push_back(maxcache);
            }
        }
        return ret;
    }
};

void test(const vector<int>& nums, int k, const vector<int>& expect) {
    print(nums);
    print(k);
    Solution s;
    auto ret = s.maxSlidingWindow(nums, k);
    if (ret == expect) {
        print("ok");
    } else {
        print("##### not ok");
        print(expect);
        print(ret);
    }
    print();
}

int main() {
    test({7, 2, 4}, 2, {7, 4});
    test({1, 3, -1, -3, 5, 3, 6, 7}, 3, {3, 3, 5, 5, 6, 7});
    test({1}, 1, {1});
    return 0;
}
