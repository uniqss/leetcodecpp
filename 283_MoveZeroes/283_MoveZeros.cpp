#include "../inc.h"

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
    }
};

int main() {
    Solution s;
    vector<int> vi;
    vi = {1, 0, 2, 3, 0, 4};
    s.moveZeroes(vi);
    print(vi);

    vi = {0, 1, 0, 0, 5, 0};
    s.moveZeroes(vi);
    print(vi);
    return 0;
}
