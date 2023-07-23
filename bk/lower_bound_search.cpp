#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;

int upper_bound_binary_search(const vector<int>& nums, int val) {
    if (nums.empty()) return -1;
    if (nums[0] > val) return nums[0];

#if 1
    // auto it = std::upper_bound(nums.begin(), nums.end(), val);
    auto it = std::upper_bound(nums.begin(), nums.end(), val, [](int val, int i) { return i > val; });
    if (it == nums.end()) return -1;
    return *it;
#else
    auto nsize = nums.size();
    if (nums[nsize - 1] <= val) return -1;

    int first = 0, last = nsize, it;
    int count = last - first, step;
    while (count > 0) {
        step = count / 2;
        it = first + step;

        if (!(val < nums[it])) {
            first = ++it;
            count -= step + 1;
        } else {
            count = step;
        }
    }

    return nums[first];
#endif
}

void test(const vector<int>& nums, int val, int expect) {
    auto ret = upper_bound_binary_search(nums, val);
    if (ret == expect) {
        cout << "ok" << endl;
    } else {
        cout << "not ok." << endl;
        cout << "{";
        for (int n : nums) {
            cout << n << ", ";
        }
        cout << "}" << endl;
        cout << "val:" << val << "\t";
        cout << "expect:" << expect << "\t";
        cout << "ret:" << ret << endl;
        cout << endl;
    }
}

int main() {
    test({1, 3, 5, 7}, 0, 1);
    test({1, 3, 5, 7}, 1, 3);
    test({1, 3, 5, 7}, 2, 3);
    test({1, 3, 5, 7}, 3, 5);
    test({1, 3, 5, 7}, 4, 5);
    test({1, 3, 5, 7}, 5, 7);
    test({1, 3, 5, 7}, 6, 7);
    test({1, 3, 5, 7}, 7, -1);
    test({1, 3, 5, 7}, 8, -1);
    return 0;
}
