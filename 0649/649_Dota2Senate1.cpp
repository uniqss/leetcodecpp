#include "../inc.h"

/*
中文官方题解，鬼斧神工。完美的还原了整个过程：
1.a seal b, b directly out
2.after a seal b, a can not seal anyone, but a is still alive, need to be sealed
它这等于就是，用两个队，R队如果队头小于D队，R队头的人到R队尾排队，并且序号等于之前序号加n，D队头出列
*/
class Solution {
   public:
    string predictPartyVictory(string senate) {
        int ssize = senate.size();
        queue<int> d, r;
        for (int i = 0; i < ssize; ++i) {
            if (senate[i] == 'D')
                d.push(i);
            else
                r.push(i);
        }
        while (!d.empty() && !r.empty()) {
            if (d.front() < r.front()){
                d.push(d.front() + ssize);
            } else {
                r.push(r.front() + ssize);
            }
            d.pop();
            r.pop();
        }
        return !d.empty() ? "Dire" : "Radiant";
    }
};

void test(string senate, const string& expect) {
    Solution so;
    auto ret = so.predictPartyVictory(senate);
    assert_eq_ret(expect, ret);
    print(senate);
}

int main() {
    test("DDRRR", "Dire");
    test("RD", "Radiant");
    test("DR", "Dire");
    test("RDD", "Dire");

    return 0;
}
