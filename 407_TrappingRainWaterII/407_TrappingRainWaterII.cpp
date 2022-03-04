#include "../inc.h"

class Solution {
   public:
    int trapRainWater(vector<vector<int>>& heightMap) {
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
