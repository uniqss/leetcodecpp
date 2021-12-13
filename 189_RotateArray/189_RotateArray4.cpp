#include "../stl.h"

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    Solution s;
    vector<int> vi;

    vi = {1, 2, 3, 4, 5, 6, 7};
    s.rotate(vi, 3);
    pvi(vi);

    vi = {-1, -100, 3, 99};
    s.rotate(vi, 2);
    pvi(vi);

    return 0;
}
