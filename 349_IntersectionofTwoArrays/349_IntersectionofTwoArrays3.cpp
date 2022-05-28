#include "../inc.h"

class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), &r1 = s1, &r2 = s2, s;

        if (r1.size() < r2.size()) std::swap(r1, r2);
        for (int n : r2) {
            if (r1.count(n) > 0) s.insert(n);
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
        praw("ok.");
    } else {
        praw("not ok.");
        pvraw(num1);
        pvraw(num2);
        pvraw(expect);
        pvraw(ret);
        pnewline();
    }
}


int main() {
    test({1, 2, 2, 1}, {2, 2}, {2});
    test({4, 9, 5}, {9, 4, 9, 8, 4}, {9, 4});
    return 0;
}
