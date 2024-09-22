#include "../inc.h"

class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size(), vmax = arr[n - 1], tmp;
        for (int i = n - 2; i >= 0; --i) {
            tmp = vmax;
            vmax = std::max(arr[i], vmax);
            arr[i] = tmp;
        }
        arr[n - 1] = -1;
        return arr;
    }
};

void test(vector<int>&& arr, const vector<int>& expect) {
    save4print(arr);
    assert_eq_ret(expect, Solution().replaceElements(arr));
}

int main() {
    test({17, 18, 5, 4, 6, 1}, {18, 6, 6, 6, 1, -1});
    test({400}, {-1});
    return 0;
}
