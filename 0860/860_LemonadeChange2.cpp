#include "../inc/inc.h"

class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0, count10 = 0;
        for (int bill : bills) {
            if (bill == 5) {
                ++count5;
                continue;
            } else if (bill == 10) {
                if (--count5 < 0) return false;
                ++count10;
            } else if (bill == 20) {
                if (count10 > 0 && count5 > 0) {
                    --count10;
                    --count5;
                    continue;
                }
                if (count5 >= 3) {
                    count5 -= 3;
                    continue;
                }
                return false;
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
