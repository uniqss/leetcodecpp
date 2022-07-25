#include "../inc.h"

/*
这可能不是最优解， 但是应该是最符合人的思维的解
*/
class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int x = 0, y = 0, xnext = 0, ynext = 0;
        // 注意这里 计算机的二维数组和x/y维度和人的思维是反的，所以看起来这里x向的偏移是人的思维里的y向
        vector<int> mx = {0, 1, 0, -1};
        vector<int> my = {1, 0, -1, 0};
        int direction = 0;
        int n2 = n * n;
        for (int i = 0; i < n2; ++i) {
            ret[x][y] = i + 1;
            xnext = x + mx[direction];
            ynext = y + my[direction];

            // 跟贪吃蛇一样，如果撞墙，转向
            if (xnext < 0 || xnext >= n || ynext < 0 || ynext >= n || ret[xnext][ynext] != 0) {
                direction = (direction + 1) % 4;
                xnext = x + mx[direction];
                ynext = y + my[direction];
            }
            x = xnext;
            y = ynext;
        }

        return ret;
    }
};

void test(int n, const vector<vector<int>>& expect) {
    Solution so;
    auto ret = so.generateMatrix(n);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(n);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test(4, {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}});
    test(3, {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}});
    test(1, {{1}});
    return 0;
}
