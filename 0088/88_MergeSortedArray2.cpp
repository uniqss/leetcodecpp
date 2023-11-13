#include "../inc.h"

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m + n);
        --m;
        --n;
        while (m >= 0 && n >= 0) {
            if (nums1[m] >= nums2[n]) {
                nums1[m + n + 1] = nums1[m];
                --m;
            } else {
                nums1[m + n + 1] = nums2[n];
                --n;
            }
        }
        while (n >= 0) {
            nums1[n] = nums2[n];
            --n;
        }
    }
};

void test(std::vector<int>&& v1, int m, std::vector<int>&& v2, int n, const vector<int>& expect) {
    save4print(v1, m, v2, n);
    Solution().merge(v1, m, v2, n);
    assert_eq_ret(expect, v1);
}

int main() {
    test({2, 0}, 1, {1}, 1, {1, 2});
    test({1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3, {1, 2, 2, 3, 5, 6});
    test({1, 2, 3, 6, 0, 0, 0}, 4, {2, 5, 7}, 3, {1, 2, 2, 3, 5, 6, 7});
    test({1}, 1, {}, 0, {1});
    test({0}, 0, {1}, 1, {1});

    return 0;
}
