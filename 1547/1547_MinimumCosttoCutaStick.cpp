#include "../inc.h"

/*
60
 29 30 40 50
30:
60 + 30 + 30 + 20
29:
60 + 31 + 11 + 20
40:
60 + 40 + 11 + 20
在偷看了这个题的标签是dp以后，瞬间觉得自己能搞定，燃
*/
class Solution {
   public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        int nsize = cuts.size();
        vector<vector<int>> dict(nsize, vector<int>(0));

        int ret = 0;
        int mid = 0;
        return ret;
    }
};

void test(int n, vector<int>&& cuts, int expect) {
    Solution so;
    auto ret = so.minCost(n, cuts);
    auto cuts_param = cuts;
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(n);
        print(cuts_param);
        print(expect);
        print(ret);
    }
}

int main() {
    test(7, {1, 3, 4, 5}, 16);
    test(9, {5, 6, 1, 4, 2}, 22);
    return 0;
}
