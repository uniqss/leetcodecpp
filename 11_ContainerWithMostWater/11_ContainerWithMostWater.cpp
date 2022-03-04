#include "../inc.h"

class Solution {
   public:
    int maxArea(vector<int> &height) {
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> vi;
    int ret = 0;

    vi = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    ret = s.maxArea(vi);
    cout << ret << endl;

    vi = {1, 1};
    ret = s.maxArea(vi);
    cout << ret << endl;

    vi = {4, 3, 2, 1, 4};
    ret = s.maxArea(vi);
    cout << ret << endl;

    vi = {1, 2, 1};
    ret = s.maxArea(vi);
    cout << ret << endl;

    return 0;
}
