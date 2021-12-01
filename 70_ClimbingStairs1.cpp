#include "stl.h"

class Solution {
   public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    int ret = s.climbStairs(3);
    cout << ret << endl;
    return 0;
}
