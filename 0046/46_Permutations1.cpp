#include "../inc.h"

/*
这个算法自己 搞出来的，恐怕整个 网上独一份了，不过太容易出错了，还是官方的递归和人的思路更近
*/
class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        size_t nsize = nums.size();
        vector<int> vidx(nsize);
        for (size_t i = 0; i < nsize; ++i) {
            vidx[i] = i;
        }

        vector<int> val(nsize);
        for (size_t i = 0; i < nsize; ++i) {
            val[i] = nums[vidx[i]];
        }
        ret.emplace_back(val);

        while (true) {
            int pos = -1;
            for (int i = nsize - 1; i > 0; --i) {
                if (vidx[i] > vidx[i - 1]) {
                    pos = i - 1;
                    break;
                }
            }
            if (pos == -1) break;
            int larger_right = nsize - 1;
            int larger_val = INT_MAX;
            for (int i = nsize - 1; i >= pos; --i) {
                if (vidx[i] > vidx[pos] && vidx[i] < larger_val) {
                    larger_right = i;
                    larger_val = vidx[i];
                }
            }

            swap(vidx[pos], vidx[larger_right]);
            if (pos < (int)nsize - 2) std::sort(vidx.begin() + pos + 1, vidx.end());

            for (size_t i = 0; i < nsize; ++i) {
                val[i] = nums[vidx[i]];
            }
            ret.emplace_back(val);
        }
        return ret;
    }
};

void test(vector<int>&& nums, vector<vector<int>>&& expect) {
    save4print(nums);
    auto ret = Solution().permute(nums);
    sortvvrawInnerAndOuter(expect, ret);
    assert_eq_ret(expect, ret);
}

int main() {
    test({1, 2, 3}, {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}});
    test({0, 1}, {{0, 1}, {1, 0}});
    test({1}, {{1}});
    return 0;
}

/*
[1,2,3]
[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
[0,1]
[[0,1],[1,0]]
[1]
[[1]]
[1,2,3,4]
[
[1,2,3,4],[1,2,4,3],[1,3,2,4],[1,3,4,2],[1,4,2,3],[1,4,3,2],
[2,1,3,4],[2,1,4,3],[2,3,1,4],[2,3,4,1],[2,4,1,3],[2,4,3,1],
[3,1,2,4],[3,1,4,2],[3,2,1,4],[3,2,4,1],[3,4,1,2],[3,4,2,1],
[4,1,2,3],[4,1,3,2],[4,2,1,3],[4,2,3,1],[4,3,1,2],[4,3,2,1]]
*/
