#include "../inc.h"

class Solution {
   public:
    int increasing_first_less(vector<int>& nums, int target) { return -1; }
    int increasing_first_greater(vector<int>& nums, int target) { return -1; }
    int increasing_equal(vector<int>& nums, int target) {}
    int decreasing_first_less(vector<int>& nums, int target) { return -1; }
    int decreasing_first_greater(vector<int>& nums, int target) { return -1; }
    int decreasing_equal(vector<int>& nums, int target) {}
};

void test(vector<int>&& nums, int target) {
    auto increasing = nums, decreasing = nums;
    int nsize = nums.size();
    sort(increasing.begin(), increasing.end(), less<int>());
    sort(decreasing.begin(), decreasing.end(), greater<int>());
    print("increasing:", increasing);
    print("decreasing:", decreasing);
    Solution so;
    auto ret1 = so.increasing_equal(increasing, target);
    bool fail1 = false, fail2 = false, fail3 = false, fail4 = false;
    int expect1 = -1;
    for (int i = 0; i < nsize; ++i)
        if (increasing[i] == target) {
            expect1 = i;
            break;
        }
    if (ret1 != expect1) {
        print(increasing, " target:", target);
        print("error. ", " expect1:", expect1, " ret1:", ret1);
    }
    auto ret2 = so.increasing_first_less(increasing, target);
    if (ret2 > 0 && (increasing[ret2] >= target || (ret2 < nsize - 1 && increasing[ret2 + 1] < target))) {
        print(increasing, " target:", target);
        print("error. ", " ret2:", ret2);
    }
    auto ret3 = so.increasing_first_greater(increasing, target);
}

int main() {
    test({10, 20, 30, 40, 50}, 30);
    test({10, 20, 30, 40, 50}, 31);
    test({10, 20, 30, 40, 50}, 29);
    test({10, 20, 30, 40, 50}, 9);
    test({10, 20, 30, 40, 50}, 10);
    test({10, 20, 30, 40, 50}, 11);
    test({10, 20, 30, 40, 50}, 49);
    test({10, 20, 30, 40, 50}, 50);
    test({10, 20, 30, 40, 50}, 51);
    test({10, 20, 30, 40}, 9);
    test({10, 20, 30, 40}, 10);
    test({10, 20, 30, 40}, 11);
    test({10, 20, 30, 40}, 19);
    test({10, 20, 30, 40}, 20);
    test({10, 20, 30, 40}, 21);
    test({10, 20, 30, 40}, 29);
    test({10, 20, 30, 40}, 30);
    test({10, 20, 30, 40}, 31);
    test({10, 20, 30, 40}, 39);
    test({10, 20, 30, 40}, 40);
    test({10, 20, 30, 40}, 41);
    return 0;
}
