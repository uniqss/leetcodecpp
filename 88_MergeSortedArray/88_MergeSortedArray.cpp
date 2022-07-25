#include "../inc.h"

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {}
};

void test(std::vector<int>&& v1, int m, std::vector<int>&& v2, int n, const vector<int>& expect) {
    Solution s;
    s.merge(v1, m, v2, n);
    auto pv1 = v1;
    auto pv2 = v2;

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
    test({1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3, {1, 2, 2, 3, 5, 6});
    test({1, 2, 3, 6, 0, 0, 0}, 4, {2, 5, 7}, 3, {1, 2, 2, 3, 5, 6, 7});
    test({1}, 1, {}, 0, {1});
    test({0}, 0, {1}, 1, {1});

    return 0;
}
