#include "../inc.h"

// 注意学习这里的pair<int, int> 直接 operator <   operator > 的用法
class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        auto get = [&](int idx) -> pair<int, int> {
            if (idx < 0 || idx >= n) return {0, 0};
            return {1, nums[idx]};
        };
        int l = 0, r = n - 1, mid;
        // []
        while (l <= r) {
            mid = l + (r - l) / 2;
            auto vmid = get(mid), vmidl = get(mid - 1), vmidr = get(mid + 1);
            if (vmid > vmidl && vmid > vmidr) return mid;
            if (vmid > vmidl) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};

void test(vector<int>&& nums) {
    save4print(nums);
    auto ret = Solution().findPeakElement(nums);
    int64_t vret = nums[ret];
    int64_t vl = ret > 0 ? nums[ret - 1] : (int64_t)INT_MIN - 1;
    int64_t vr = ret < nums.size() - 1 ? nums[ret + 1] : (int64_t)INT_MIN - 1;
    assert_eq_ret(vret > vl && vret > vr, true);
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
