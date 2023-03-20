#include "../inc/inc.h"

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0 || nums.size() == 1) return;

        vector<int> tmp;
        int left = nums.size() - k;
        if (left < k) {
            tmp.resize(left);
            std::copy(nums.begin(), nums.begin() + left, tmp.begin());
            std::copy(nums.begin() + left, nums.end(), nums.begin());
            std::copy(tmp.begin(), tmp.end(), nums.begin() + k);
        } else {
            tmp.resize(k);
            std::copy(nums.begin() + left, nums.end(), tmp.begin());
            std::copy(nums.begin(), nums.begin() + left, nums.begin() + k);
            std::copy(tmp.begin(), tmp.end(), nums.begin());
        }
    }
};

void test(vector<int>&& nums, int k, const vector<int>& expect) {
    vector<int> pnums = nums;
    Solution so;
    so.rotate(nums, k);
    if (nums == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(pnums);
        print(k);
        print(expect);
        print(nums);
        print();
    }
}

int main() {
    test({1, 2, 3, 4, 5, 6, 7}, 3, {5, 6, 7, 1, 2, 3, 4});
    test({-1, -100, 3, 99}, 2, {3, 99, -1, -100});

    return 0;
}
