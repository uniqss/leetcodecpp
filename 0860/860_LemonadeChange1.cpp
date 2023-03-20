#include "../inc/inc.h"

class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0;
        int count10 = 0;
        int count20 = 0;
        for (int bill : bills) {
            if (bill == 5) {
                ++count5;
                continue;
            } else if (bill == 10) {
                if (count5 <= 0) return false;
                --count5;
                ++count10;
            } else {
                if (count10 > 0 && count5 > 0) {
                    --count10;
                    --count5;
                } else if (count5 >= 3) {
                    count5 -= 3;
                } else {
                    return false;
                }
                ++count20;
            }
        }
        return true;
    }
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
