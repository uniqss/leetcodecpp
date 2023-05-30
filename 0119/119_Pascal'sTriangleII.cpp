#include "../inc.h"

class Solution {
   public:
    vector<int> getRow(int rowIndex) {}
};

void test(int rowIndex, const vector<int>& expect) {
    Solution so;
    auto ret = so.getRow(rowIndex);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(rowIndex);
        print(expect);
        print(ret);
    }
}

int main() {
    test(3, {1, 3, 3, 1});
    test(0, {1});
    test(1, {1, 1});
    return 0;
}
