#include "../inc.h"

class Solution {
   public:
    void reverseString(vector<char>& s) {}
};

void test(vector<char>&& s, const vector<char>& expect) {
    vector<char> input = s;
    Solution so;
    so.reverseString(s);
    if (s == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(s);
        print(expect);
        print(s);
        print();
    }
}

int main() {
    test({'h', 'e', 'l', 'l', 'o'}, {'o', 'l', 'l', 'e', 'h'});
    test({'H', 'a', 'n', 'n', 'a', 'h'}, {'h', 'a', 'n', 'n', 'a', 'H'});
    return 0;
}
