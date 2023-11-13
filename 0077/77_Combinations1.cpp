#include "../inc.h"

// 这个算法没问题，但会超时，剪枝策略不足
/*
o o o o o o x x x x x
o o o o o x x x x x o
o o o o x x x x x o o
o o o x x x x x o o o
o o x x x x x o o o o
o x x x x x o o o o o
x x x x x o o o o o o
应该是上图中只访问中间x区间的数据，把上面的o和下面的o都要剪掉，超时的测试用例是13 13，所有n=k都是一条直线，只有一个解
o o o o x
o o o x o
o o x o o
o x o o o
x o o o o

4 2的解：
o o   o o   o x   o o   o x   o x
o o   o x   o o   o x   o o   x o
o x   o o   o o   x o   x o   o o
x o   x o   x o   o o   o o   o o
4 3的解：
o o o   o o x   o o x   o o x
o o x   o o o   o x o   o x o
o x o   o x o   o o o   x o o
x o o   x o o   x o o   o o o
规律：
首先初值所有递增
保持元素递增不要减
末位开始，可以往上加则往上加
末位不能往上加，以［最终斜向递减值］往前找到第一个可以加的轮，增加
往上加本位清零策略：往上加了以后后面轮的值统一清到以最后一个新加值斜向上的图形
参见2的实现

*/
class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        int64_t nk = std::pow((int64_t)n, (int64_t)k);
        int nval[20];
        int64_t vcurr = 0;
        bool vcurr_valid = false;
        for (int64_t v = 0; v < nk; ++v) {
            vcurr = v;
            vcurr_valid = true;
            for (int wheel = 0; wheel < k; ++wheel) {
                nval[wheel] = (vcurr % n) + 1;
                vcurr = vcurr / n;
                if (wheel > 0 && nval[wheel] <= nval[wheel - 1]) {
                    vcurr_valid = false;
                    break;
                }
            }
            if (vcurr_valid) {
                ret.resize(ret.size() + 1);
                for (int i = 0; i < k; ++i) {
                    ret[ret.size() - 1].emplace_back(nval[i]);
                }
            }
        }
        return ret;
    }
};

void test(int n, int k, vector<vector<int>>&& expect) {
    auto ret = Solution().combine(n, k);
    sortvvrawInnerAndOuter(expect, ret);
    assert_eq_ret(expect, ret);
}

/*
1 <= n <= 20
1 <= k <= n
*/
int main() {
    test(4, 2,
         {
             {2, 4},
             {3, 4},
             {2, 3},
             {1, 2},
             {1, 3},
             {1, 4},
         });
    test(1, 1, {{1}});
    test(13, 13, {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}});
    return 0;
}

/*
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
