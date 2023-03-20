#include "../inc/inc.h"

class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        for (int num1 : nums1) {
            dict[num1] = 1;
        }
        vector<int> ret;
        for (int num2 : nums2) {
            if (dict[num2] == 1) {
                ret.emplace_back(num2);
                ++dict[num2];
            }
        }
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
