#include "../inc.h"

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int n : nums) {
            q.emplace(n);
            if (q.size() > k) q.pop();
        }
        return q.top();
    }
};

void test(vector<int>&& nums, int k, int expect) {
    auto n_param = nums;
    Solution so;
    auto ret = so.findKthLargest(nums, k);
    assert_eq_ret(expect, ret);
    print(n_param);
    print(k);
}

int main() {
    test({7, 6, 5, 4, 3, 2, 1}, 2, 6);
    test({3, 2, 1, 5, 6, 4}, 2, 5);
    test({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4, 4);
    return 0;
}
