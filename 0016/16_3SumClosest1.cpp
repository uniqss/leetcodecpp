#include "../inc.h"

class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = 100000, ret = 0;
        sort(nums.begin(), nums.end());
        int nsize = nums.size();
        for (int i = 0; i < nsize - 2; ++i) {
            int l = i + 1, r = nsize - 1, sum = 0;
            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                int currdiff = abs(target - sum);
                if (currdiff < diff) {
                    diff = currdiff;
                    ret = sum;
                }
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    while (l < r && nums[l] == nums[l + 1]) ++l;
                    ++l;
                } else {
                    while (l < r && nums[r] == nums[r - 1]) --r;
                    --r;
                }
            }
        }
        return ret;
    }
};

void test(vector<int>&& nums, int target, int expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.threeSumClosest(nums, target);
    if (expect == ret) {
        print("ok");
    } else {
        print("not ok");
        print(nums_param);
        print(target);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({-13,  592,  -501, 770,  -952, -675, 322,  -829, -246, 657,  608,  485,  -112, 967,  -30,  182,  -969,
          559,  -286, -64,  24,   365,  -158, 701,  535,  -429, -217, 28,   948,  -114, -536, -711, 693,  23,
          -958, -283, -700, -672, 311,  314,  -712, -594, -351, 658,  747,  949,  70,   888,  166,  495,  244,
          -380, -654, 454,  -281, -811, -168, -839, -106, 877,  -216, 523,  -234, -8,   289,  -175, 920,  -237,
          -791, -976, -509, -4,   -3,   298,  -190, 194,  -328, 265,  150,  210,  285,  -176, -646, -465, -97,
          -107, 668,  892,  612,  -54,  -272, -910, 557,  -212, -930, -198, 38,   -365, -729, -410, 932,  4,
          -565, -329, -456, 224,  443,  -529, -428, -294, 191,  229,  112,  -867, -163, -979, 236,  -227, -388,
          -209, 984,  188,  -549, 970,  951,  -119, -146, 801,  -554, 564,  -769, 334,  -819, -356, -724, -219,
          527,  -405, -27,  -759, 722,  -774, 758,  394,  146,  517,  870,  -208, 742,  -782, 336,  -364, -558,
          -417, 663,  -914, 536,  293,  -818, 847,  -322, 408,  876,  -823, 827,  167},
         7175, 2921);

    test({1, 1, 1, 0}, -100, 2);
    test({-1, 2, 1, -4}, 1, 2);
    test({0, 0, 0}, 1, 0);

    return 0;
}
