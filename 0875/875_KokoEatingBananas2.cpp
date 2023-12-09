#include "../inc.h"

// 中文官方经典算法
// 1.学习整型值的ceil算法 ceil(num / div) = (num + div - 1) / div
// 2.类似这种二分的速度是要远超一个一个加的暴力算法的，能二分不暴力加，学习这种二分跑完全程，一直更新合法值的方式
class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 0;
        for (int p : piles) high = max(high, p);
        int ret = high;
        while (low < high) {
            int speed = low + (high - low) / 2;
            int currhour = getHour(piles, speed);
            if (currhour <= h) {
                ret = min(ret, speed);
                high = speed;
            } else {
                low = speed + 1;
            }
        }
        return ret;
    }
    int getHour(const vector<int>& piles, int speed) {
        int ret = 0;
        for (int p : piles) {
            ret += (p + speed - 1) / speed;
        }
        return ret;
    }
};

void test(vector<int>&& piles, int h, int expect) {
    save4print(piles, h);
    assert_eq_ret(expect, Solution().minEatingSpeed(piles, h));
}

int main() {
    test({312884470}, 968709470, 1);
    test({3, 6, 7, 11}, 8, 4);
    test({30, 11, 23, 4, 20}, 5, 30);
    test({30, 11, 23, 4, 20}, 6, 23);
    return 0;
}
