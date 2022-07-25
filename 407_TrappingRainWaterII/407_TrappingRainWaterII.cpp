#include "../inc.h"

class Solution {
   public:
    int trapRainWater(vector<vector<int>>& heightMap) {
    }
};

void test(vector<vector<int>>&& vvi, int expect) {
    print(vvi);
    Solution s;
    int ret = s.trapRainWater(vvi);
    if (ret == expect) {
        print("ok");
    } else {
        print("### not ok ");
        print(expect);
        print(ret);
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
