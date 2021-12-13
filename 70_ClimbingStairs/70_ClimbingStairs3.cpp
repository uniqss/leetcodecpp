#include "stl.h"

class Solution {
   public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int top = 1;
        int after = 1;
        int tmp = 0;
        for (int i = 2;i <= n;++i) {
            tmp = top + after;
            after = top;
            top = tmp;
        }
        return top;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    int ret = s.climbStairs(10);
    cout << ret << endl;
    return 0;
}
