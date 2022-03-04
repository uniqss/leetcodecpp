#include "../inc.h"

// 效仿I里面推模型，往四个方向推----静态模型推动的形式这里行不通，因为水会拐弯
class Solution {
   public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() < 2 || heightMap[0].size() < 2) return 0;
        int l = heightMap.size();
        int w = heightMap[0].size();
        int ret = 0;
        vector<vector<int>> dpl1(l, vector<int>(w));
        vector<vector<int>> dpl2(l, vector<int>(w));
        vector<vector<int>> dpw1(l, vector<int>(w));
        vector<vector<int>> dpw2(l, vector<int>(w));
        dpl1[0] = heightMap[0];
        dpl2[l - 1] = heightMap[l - 1];
        for (size_t i = 0; i < l; ++i) {
            dpw1[i][0] = heightMap[i][0];
        }
        for (size_t i = 0; i < l; ++i) {
            dpw1[i][w - 1] = heightMap[i][w - 1];
        }
        // 持w移l
        for (size_t idxl = 1; idxl < l; ++idxl) {
            for (size_t idxw = 0; idxw < w; ++idxw) {
            }
        }

        return ret;
    }
};

void test(vector<vector<int>>&& vvi, int expect) {
    pvvraw(vvi);
    Solution s;
    int ret = s.trapRainWater(vvi);
    if (ret == expect) {
        praw("ok");
    } else {
        praw("### not ok ");
        praw(expect);
        praw(ret);
    }
}

int main() {
    test({{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}}, 4);
    test({{3, 3, 3, 3, 3}, {3, 2, 2, 2, 3}, {3, 2, 1, 2, 3}, {3, 2, 2, 2, 3}, {3, 3, 3, 3, 3}}, 10);
    return 0;
}

/*
{{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}}
4
{{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}}
10
*/
