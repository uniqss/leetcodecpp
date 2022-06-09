#include "../inc.h"

class Solution {
   public:
    void reverseString(vector<char>& s) {
        for (size_t i = 0, j = s.size() - 1; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
    }
};

void test(vector<char>&& s, const vector<char>& expect) {
    vector<char> input = s;
    Solution so;
    so.reverseString(s);
    if (s == expect) {
        praw("ok");
    } else {
        praw("not ok.");
        pvraw(s);
        pvraw(expect);
        pvraw(s);
        pnewline();
    }
}

int main() {
    test({'h', 'e', 'l', 'l', 'o'}, {'o', 'l', 'l', 'e', 'h'});
    test({'H', 'a', 'n', 'n', 'a', 'h'}, {'h', 'a', 'n', 'n', 'a', 'H'});
    return 0;
}
