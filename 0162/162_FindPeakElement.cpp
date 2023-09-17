#include "../inc.h"

class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        auto get = [&](int i) -> pair<int, int> {
            if (i == -1 || i == n) {
                return {0, 0};
            }
            return {1, nums[i]};
        };

        int left = 0, right = n - 1, ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (get(mid - 1) < get(mid) && get(mid) > get(mid + 1)) {
                ans = mid;
                break;
            }
            if (get(mid) < get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

void test(vector<int>&& nums) {
    auto n_param = nums;
    Solution so;
    auto ret = so.findPeakElement(nums);
    bool ok = true;
    if (ret < 0 || ret >= nums.size())
        ok = false;
    else if (n_param.size() == 1) {
        if (ret != 0) ok = false;
    } else if (n_param.size() == 2) {
        if (ret != (n_param[0] > n_param[1] ? 0 : 1)) ok = false;
    } else if (n_param[ret] <= n_param[ret - 1] || n_param[ret] <= n_param[ret + 1])
        ok = false;
    if (!ok) {
        print("not ok");
        print(n_param);
        print(ret);
    } else {
        print("ok");
    }
}

int main() {
    test({3, 4, 3, 2, 1});
    test({6, 5, 4, 3, 2, 3, 2});
    test({1});
    test({1, 2});
    test({2, 1});
    test({1, 3, 2});
    test({1, 2, 3, 1});
    test({1, 2, 1, 3, 5, 6, 4});
    return 0;
}
