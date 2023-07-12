#include "../inc.h"

/*
中文里面看到的更完美更容易理解的解法：
贪心，因为值都>=1，在最前面加个0，理解为股票就行了。获取每一段上涨利润，包括从0到nums[0]的上涨
短视，每次只看当前和前一天，如果涨，就把涨的值加上去，并把当前值存起来后面用
*/
class Solution {
   public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ret = 0;
        int pre = 0;
        for (int num : nums) {
            if (num > pre) ret += num - pre;
            pre = num;
        }
        return ret;
    }
};

void test(vector<int>&& nums, long long expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.maxAlternatingSum(nums);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(nums_param);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({4, 2, 5, 3}, 7);
    test({5, 6, 7, 8}, 8);
    test({6, 2, 1, 2, 4, 5}, 10);
    return 0;
}
