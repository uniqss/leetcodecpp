#include "../inc/inc.h"

class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {}
};

void test(vector<int>&& g, vector<int>&& s, int expect) {
    auto g_param = g;
    auto s_param = s;
    Solution so;
    auto ret = so.findContentChildren(g, s);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(g_param);
        print(s_param);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({1, 2, 3}, {1, 1}, 1);
    test({1, 2}, {1, 2, 3}, 2);
    return 0;
}
