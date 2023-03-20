#include "../inc/inc.h"

class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> s1(nums1.begin(), nums1.end()), s;

        for (int num2 : nums2) {
            if (s1.count(num2) > 0) s.insert(num2);
        }

        vector<int> ret(s.begin(), s.end());

        return ret;
    }
};

void test(vector<int>&& num1, vector<int>&& num2, vector<int>&& expect) {
    Solution so;
    auto ret = so.intersection(num1, num2);
    std::sort(ret.begin(), ret.end());
    std::sort(expect.begin(), expect.end());
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(num1);
        print(num2);
        print(expect);
        print(ret);
        print();
    }
}


int main() {
    test({1, 2, 2, 1}, {2, 2}, {2});
    test({4, 9, 5}, {9, 4, 9, 8, 4}, {9, 4});
    return 0;
}
