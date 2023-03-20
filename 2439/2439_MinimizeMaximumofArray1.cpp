#include "../inc.h"

/*
这是个数学题目，因为只能前加后减，所以只用考虑前面是一马平川，后面来一个新元素的所有可能性即可
新元素比前面的一马平川最大值小或相等，返回值依然是前面一马平川的最小值
新元素比前面的一马平川最大值大，这时候需要重新计算一下总和除以总个数，算出新的平均值。
    这时候有两种情况：
        如果遇到一个非常大的数，或者前面没有遇到足够多的小的数，新的平均值大于原来一马平川的平均值，更新
        如果遇到一个不是非常大的数，且前面遇到有较多的小的数，形成坑洼，新的平均值反而比原来一马平川的平均值要小，这时候不更新最大值，
            因为只能前加后减，前面已经形成高地，后面的洼地是没法前减后加的
*/

class Solution {
   public:
    int minimizeArrayValue(vector<int>& nums) {
        int64_t sum = 0, currmax = 0, avg, mod, newmax;
        int count = 0;
        for (int num : nums) {
            if (num <= currmax) {
                sum += num;
                ++count;
                continue;
            } else {
                sum += num;
                ++count;
                avg = sum / count;
                mod = sum % count;
                newmax = mod == 0 ? avg : avg + 1;
                currmax = max(currmax, newmax);
            }
        }

        return currmax;
    }
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
