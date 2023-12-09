#include "../inc.h"

// 硬刚过去了，没二分
class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int psize = piles.size();
        int speedmin = 1, speedmax = 0;
        int64_t sum = 0;
        for (int p : piles) {
            speedmax = max(speedmax, p);
            sum += p;
        }
        speedmin = sum / h;
        if (sum % h != 0) ++speedmin;
        for (int speed = speedmin; speed <= speedmax; ++speed) {
            int currhour = 0;
            for (int p : piles) {
                if (p % speed != 0) ++currhour;
                currhour += p / speed;
                if (currhour > h) break;
            }
            if (currhour <= h) return speed;
        }
        return -1;
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
