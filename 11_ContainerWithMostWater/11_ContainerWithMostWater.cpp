#include "../inc.h"

class Solution {
   public:
    int maxArea(vector<int> &height) {}
};

void test(vector<int> &&height, int expect) {
    const vector<int> param_height = height;
    Solution so;
    auto ret = so.maxArea(height);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(param_height);
        print(expect);
        print(ret);
        print();
    }
}

int main(int argc, char const *argv[]) {
    test({1, 8, 6, 2, 5, 4, 8, 3, 7}, 49);
    test({1, 1}, 1);
    test({4, 3, 2, 1, 4}, 16);
    test({1, 2, 1}, 2);

    return 0;
}
