#include "../inc.h"

class Solution {
   public:
    int maxConsecutiveAnswers(string answerKey, int k) {}
};

void test(string answerKey, int k, int expect) {
    Solution so;
    auto ret = so.maxConsecutiveAnswers(answerKey, k);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(answerKey);
        print(k);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test("TTFF", 2, 4);
    test("TFFT", 1, 3);
    test("TTFTTFTT", 1, 5);
    return 0;
}
