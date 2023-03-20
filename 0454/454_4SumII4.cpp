#include "../inc/inc.h"

/*
异曲同工
*/

class Solution {
   public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ret = 0;
        unordered_map<int, int> sum12count;
        for (int n1 : nums1) {
            for (int n2 : nums2) {
                ++sum12count[0 - n1 - n2];
            }
        }
        for (int n3 : nums3) {
            for (int n4 : nums4) {
                auto it = sum12count.find(n3 + n4);
                if (it != sum12count.end()) ret += it->second;
            }
        }
        return ret;
    }
};

void test(vector<int>&& nums1, vector<int>&& nums2, vector<int>&& nums3, vector<int>&& nums4, int expect) {
    Solution so;
    auto ret = so.fourSumCount(nums1, nums2, nums3, nums4);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(nums1);
        print(nums2);
        print(nums3);
        print(nums4);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({1, 2}, {-2, -1}, {-1, 2}, {0, 2}, 2);
    test({0}, {0}, {0}, {0}, 1);
    return 0;
}
