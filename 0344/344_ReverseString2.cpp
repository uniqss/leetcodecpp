#include "../inc/inc.h"

class Solution {
   public:
    void reverseString(vector<char>& s) {
        int loop = s.size() / 2;
        int ssize = s.size();
        for (int i = 0; i < loop; ++i) {
            swap(s[i], s[ssize - i - 1]);
        }
    }
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
