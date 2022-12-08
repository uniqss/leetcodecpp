#include "../inc.h"

/* 对1的优化
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

n = 4   k = 2:
o o   o o   o x   o o   o x   o x
o o   o x   o o   o x   o o   x o
o x   o o   o o   x o   x o   o o
x o   x o   x o   o o   o o   o o
n = 4   k = 3:
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
*/
class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> data(k);
        for (int i = 1; i <= k; ++i) {
            data[i - 1] = i;
        }
        ret.emplace_back(data);

        while (true) {
            int curr_wheel = -1;
            for (int wheel = k - 1; wheel >= 0; --wheel) {
                if (data[wheel] < (n - (k - wheel - 1))) {
                    curr_wheel = wheel;
                    break;
                }
            }
            if (curr_wheel == -1) break;
            ++data[curr_wheel];
            if (data[curr_wheel] < n - (k - curr_wheel - 1)) {
                int data_curr = data[curr_wheel];
                for (int i = curr_wheel + 1; i < k; ++i) {
                    ++data_curr;
                    data[i] = data_curr;
                }
            }
            ret.emplace_back(data);
        }

        return ret;
    }
};

void test(int n, int k, vector<vector<int>>&& expect) {
    Solution s;
    auto ret_raw = s.combine(n, k);
    auto ret = ret_raw;
    std::for_each(ret.begin(), ret.end(), [](vector<int>& v) { std::sort(v.begin(), v.end()); });
    std::sort(ret.begin(), ret.end(),
              [](const vector<int>& lhs, const vector<int>& rhs) { return std::accumulate(lhs.begin(), lhs.end(), 0) > std::accumulate(rhs.begin(), rhs.end(), 0); });
    std::for_each(expect.begin(), expect.end(), [](vector<int>& v) { std::sort(v.begin(), v.end()); });
    std::sort(expect.begin(), expect.end(),
              [](const vector<int>& lhs, const vector<int>& rhs) { return std::accumulate(lhs.begin(), lhs.end(), 0) > std::accumulate(rhs.begin(), rhs.end(), 0); });
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(n);
        print(k);
        print(expect);
        print(ret_raw);
    }
    print();
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
