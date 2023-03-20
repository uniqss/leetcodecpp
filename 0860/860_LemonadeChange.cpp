#include "../inc.h"

class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {}
};

void test(vector<int>&& bills, bool expect) {
    vector<int> bills_param = bills;
    Solution so;
    auto ret = so.lemonadeChange(bills);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(bills_param);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({5, 5, 5, 10, 20}, true);
    test({5, 5, 10, 10, 20}, false);
    return 0;
}
