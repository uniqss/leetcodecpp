#include "../inc.h"


class Solution {
   public:
    string replaceSpaces(string S, int length) {
        int spaceCount = 0;
        for (size_t i = 0; i < S.size() && i < length; ++i) {
            if (S[i] == ' ') ++spaceCount;
        }
        S.resize(length + spaceCount * 2);
        --length;
        for (; length >= 0; --length) {
            if (S[length] == ' ') {
                S[length + spaceCount * 2] = '0';
                S[length + spaceCount * 2 - 1] = '2';
                S[length + spaceCount * 2 - 2] = '%';
                --spaceCount;
            } else {
                S[length + spaceCount * 2] = S[length];
            }
        }
        return S;
    }
};

void test(std::string s, int length, std::string&& expect) {
    Solution so;
    auto ret = so.replaceSpaces(s, length);
    // ret.resize(length);
    // expect.resize(length);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(s);
        print(length);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test("ds sdfs afs sdfa dfssf asdf             ", 27, "ds%20sdfs%20afs%20sdfa%20dfssf%20asdf");
    test("Mr John Smith    ", 13, "Mr%20John%20Smith");
    test("               ", 5, "%20%20%20%20%20");
    return 0;
}
