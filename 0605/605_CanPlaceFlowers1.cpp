#include "../inc.h"

class Solution {
   public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        auto fsize = flowerbed.size();
        // 麻烦死了，还不如直接统计出所有空的数量
        vector<int> counts;
        int count = 0;
        for (int i = 0; i < fsize; ++i) {
            if (flowerbed[i] == 1) {
                if (i > 0) {
                    counts.push_back(count);
                    count = 0;
                }
            } else {
                ++count;
            }
        }
        if (count > 0) counts.push_back(count);
        int canplant = 0;
        if (counts.size() == 1 && counts[0] == fsize)
            canplant = (counts[0] + 1) / 2;
        else {
            // 最开始位置如果头没有种，2个空就能种1个，结尾对称
            // 中间3个位置才能种1个，5个才能种2个
            for (int i = 0; i < counts.size(); ++i) {
                if ((flowerbed[0] == 0 && i == 0) || (flowerbed[fsize - 1] == 0 && i == counts.size() - 1)) {
                    if (counts[i] >= 2) canplant += counts[i] / 2;
                } else {
                    if (counts[i] >= 3) canplant += (counts[i] - 1) / 2;
                }
            }
        }
        return canplant >= n;
    }
};

void test(vector<int>&& flowerbed, int n, bool expect) {
    auto flowerbed_param = flowerbed;
    Solution so;
    auto ret = so.canPlaceFlowers(flowerbed, n);
    assert_eq_ret(expect, ret);
    print(flowerbed_param);
    print(n);
}

int main() {
    test({1, 0, 0, 0, 0, 1}, 2, false);
    test({1, 0, 0, 0, 1}, 1, true);
    test({1, 0, 0, 0, 1}, 2, false);
    return 0;
}
