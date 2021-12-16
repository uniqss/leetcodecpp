#include "stl.h"

class Solution {
   public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int left = 1; // 0. left foot behind
        int right = 1; // 1. right foot ahead
        for (int i = 2;i <= (n + 1) / 2;++i) {
            // move left foot
            left += right;
            // move right foot
            right += left;
        }
        // we need to move one more step if the last is the left foot.
        return n % 2 == 0 ? (left + right) : right;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    int ret = 0;
    ret = s.climbStairs(2);
    cout << ret << endl;
    ret = s.climbStairs(3);
    cout << ret << endl;
    ret = s.climbStairs(4);
    cout << ret << endl;
    ret = s.climbStairs(5);
    cout << ret << endl;
    return 0;
}
