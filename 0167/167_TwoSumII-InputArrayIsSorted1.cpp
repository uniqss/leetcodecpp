#include "../inc.h"

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int nsize = numbers.size();
        int l = 0, r = numbers.size() - 1, sum = 0;
        while (true) {
            sum = numbers[l] + numbers[r];
            if (sum == target) {
                return {l + 1, r + 1};
            } else if (sum < target) {
                while (numbers[l] < target - numbers[r]) {
                    ++l;
                }
            } else {
                while (numbers[r] > target - numbers[l]) {
                    --r;
                }
            }
        }

        return {-1, -1};
    }
};

void test(vector<int>&& numbers, int target, vector<int>&& expect) {
    auto numbers_param = numbers;
    Solution so;
    auto ret = so.twoSum(numbers, target);
    std::sort(ret.begin(), ret.end());
    std::sort(expect.begin(), expect.end());
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(numbers_param);
        print(target);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({2, 7, 11, 15}, 9, {1, 2});
    test({2, 3, 4}, 6, {1, 3});
    test({-1, 0}, -1, {1, 2});
    return 0;
}
