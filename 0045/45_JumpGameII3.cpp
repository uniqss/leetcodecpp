#include "../inc.h"

// 中文官方题解2
// 这个算法纯看代码有点难懂。算法的过程：
// 1.第一次，在第0号位置，能跳则跳，跳到的位置，记为end，能跳到的远距离，记为maxpos，这里maxpos和end相等。记录跳跃次数
// 2.循环第1号位置到end - 1号位置，如果里面有能跳到更远的位置的，更新maxpos，但是不更新end
// 3.1.到end节点时，依然跟步骤2一样进行一次更远距离的尝试，并更新maxpos。
// 3.2. 更新完后，无条件往更新end到maxpos位置。记录跳跃次数
// 继续执行步骤2~3
// 最后一个节点不执行

/*
这里是取巧了，我们不需要关注是在哪个点进行的跳跃，只需要记录跳跃次数。
分析两次连续跳跃：第一步记为A，第二步记为B
在[Astart, Aend]范围内，一定有一个位置是AB总共能跳到的最远距离的Bstart.
取巧在于，我们把Astart能跳到的最远点，强制定义为X，然后再循环[Astart, X]里面，找总共能跳到的最远距离maspos.当我们到达
X点时，直接加一次跳跃次数，更新位置到maxpos。这样虽然第一次跳跃的不对，但是加上第二次，总距离和总次数是对的
*/

class Solution {
   public:
    int jump(vector<int>& nums) {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().jump(nums));
}

int main() {
    test({2, 3, 1, 1, 4}, 2);
    test({2, 3, 0, 1, 4}, 2);
    return 0;
}
