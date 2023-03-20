#include "../inc/inc.h"

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int mi = m - 1;
        int ni = n - 1;
        int idx = m + n - 1;
        nums1.resize(m + n);
        while (mi >= 0 && ni >= 0) {
            if (nums1[mi] > nums2[ni]) {
                nums1[idx--] = nums1[mi--];
            } else {
                nums1[idx--] = nums2[ni--];
            }
        }
        while (ni >= 0) {
            nums1[idx--] = nums2[ni--];
        }
    }
};

void test(std::vector<int>&& v1, int m, std::vector<int>&& v2, int n, const vector<int>& expect) {
    Solution s;
    auto pv1 = v1;
    auto pv2 = v2;
    s.merge(v1, m, v2, n);

    if (v1 == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(pv1);
        print(m);
        print(pv2);
        print(n);
        print(expect);
        print(v1);
        print();
    }
}

int main() {
    test({2, 0}, 1, {1}, 1, {1, 2});
    test({1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3, {1, 2, 2, 3, 5, 6});
    test({1, 2, 3, 6, 0, 0, 0}, 4, {2, 5, 7}, 3, {1, 2, 2, 3, 5, 6, 7});
    test({1}, 1, {}, 0, {1});
    test({0}, 0, {1}, 1, {1});

    return 0;
}
