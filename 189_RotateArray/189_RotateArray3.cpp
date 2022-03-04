#include "../inc.h"

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

int main() {
    Solution s;
    vector<int> vi;

    vi = {1, 2, 3, 4, 5, 6, 7};
    s.rotate(vi, 3);
    pvraw(vi);

    vi = {-1, -100, 3, 99};
    s.rotate(vi, 2);
    pvraw(vi);

    return 0;
}
