#include "../inc.h"

class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> dict;
        int n1 = nums1.size(), n2 = nums2.size();
        for (int i = 0; i < n2; ++i) {
            while (!stk.empty() && nums2[i] > nums2[stk.top()]) {
                dict[nums2[stk.top()]] = nums2[i];
                stk.pop();
            }
            stk.emplace(i);
        }
        for (int i = 0; i < n1; ++i) {
            auto it = dict.find(nums1[i]);
            if (it == dict.end())
                nums1[i] = -1;
            else
                nums1[i] = it->second;
        }
        return nums1;
    }
};

void test(vector<int>&& nums1, vector<int>&& nums2, const vector<int>& expect) {
    save4print(nums1, nums2);
    assert_eq_ret(expect, Solution().nextGreaterElement(nums1, nums2));
}

int main() {
    test({4, 1, 2}, {1, 3, 4, 2}, {-1, 3, -1});
    test({2, 4}, {1, 2, 3, 4}, {3, -1});
    return 0;
}
