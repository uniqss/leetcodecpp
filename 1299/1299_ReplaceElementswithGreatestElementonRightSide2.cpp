#include "../inc.h"

class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size(), tmp, vmax = -1;
        for (int i = n - 1; i >= 0; --i) {
            tmp = arr[i];
            arr[i] = vmax;
            vmax = max(vmax, tmp);
        }
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
