#include "../inc/inc.h"

class Solution {
   public:
    int minimizeArrayValue(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expect) {
    Solution so;
    auto ret = so.minimizeArrayValue(nums);
    if (ret == expect) {
        cout << "ok" << endl;
    } else {
        cout << "not ok." << endl;
        for_each(nums.begin(), nums.end(), [](int i) { cout << i << " "; });
        cout << endl;
        cout << expect << endl;
        cout << ret << endl;
    }
}

int main() {
    test({4, 7, 2, 2, 9, 19, 16, 0, 3, 15}, 9);
    test({3, 7, 1, 6}, 5);
    test({10, 1}, 10);
    return 0;
}
