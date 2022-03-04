#include "../inc.h"

/*
force
*/
class Solution {
   public:
    int maxArea(vector<int> &height) {
        int ret = 0;
        int curr = 0;
        for (int l = 0; l < height.size() - 1; ++l) {
            for (int r = l + 1; r < height.size(); ++r) {
                curr = std::min(height[l], height[r]) * (r - l);
                if (curr > ret) ret = curr;
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> vi = {1, 1};
    int ret = s.maxArea(vi);
    cout << ret << endl;
    return 0;
}
