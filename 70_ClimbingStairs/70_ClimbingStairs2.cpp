#include "stl.h"

class Solution {
   public:
    int climbStairs(int n) {
        vector<int> vi(n + 1, 1);
        for (int i = 2;i <= n;++i) {
            vi[i] = vi[i - 1] + vi[i - 2];
        }
        return vi[n];
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    int ret = s.climbStairs(10);
    cout << ret << endl;
    return 0;
}
